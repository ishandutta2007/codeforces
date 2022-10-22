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

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int sum = 0;
        int cnt0 = 0;
        int cnt2 = 0;
        for (char c : s) {
            c -= '0';
            sum += c;
            if (c == 0)
                cnt0++;
            if (c % 2 == 0) {
                cnt2++;
            }
        }
        if (sum % 3) {
            cout << "cyan\n";
            continue;
        }
        if (cnt0 > 0 && cnt2 - 1 > 0) {
            cout << "red\n";
        } else {
            cout << "cyan\n";
        }
    }

    return 0;
}