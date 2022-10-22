#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int read_int() {
    string s;
    cin >> s;
    int mask = 0;
    for (char c : s) {
        c -= '0';
        mask = mask * 2 + c;
    }
    return mask;
}

const int X = 7 * 2000 + 5;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> digits = {
            0b1110111, 0b0010010, 0b1011101,
            0b1011011, 0b0111010, 0b1101011,
            0b1101111, 0b1010010, 0b1111111,
            0b1111011
    };

    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        a[i] = read_int();

    vector<bitset<X>> can(n + 2);

    can[n + 1][0] = true;
    for (int i = n; i >= 1; i--) {
        int small_mask = a[i];
        for (int big_mask : digits) {
            if ((small_mask & big_mask) == small_mask) {
                int ad = __builtin_popcount(big_mask);
                can[i] |= can[i + 1] << ad;
            }
        }
    }

    int total = k;
    for (int i = 1; i <= n; i++)
        total += __builtin_popcount(a[i]);

    if (total >= X || !can[1][total]) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        int small_mask = a[i];
        for (int j = 9; j >= 0; j--) {
            int big_mask = digits[j];
            if ((small_mask & big_mask) == small_mask) {
                int ad = __builtin_popcount(big_mask);
                if (total >= ad && can[i + 1][total - ad]) {
                    cout << j;
                    total -= ad;
                    break;
                }
            }
        }
    }

    cout << "\n";

    return 0;
}