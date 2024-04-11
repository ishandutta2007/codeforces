#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int LOG = 30;

int op(int i, int j, string t) {
    cout << t << " " << i + 1 << " " << j + 1 << endl;
    int res;
    cin >> res;
    return res;
}

void finish(int res) {
    cout << "finish " << res << endl;
}

int main() {

//#ifdef DEBUG
//    freopen("input.txt", "r", stdin);
//#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> AND(n), OR(n), XOR(n);
    for (int i = 1; i < n; i++) {
        AND[i] = op(0, i, "and");
        OR[i] = op(0, i, "or");
        XOR[i] = AND[i] ^ OR[i];
    }

    int hlp_or = op(1, 2, "or");

    vector<int> a(n);
    for (int j = 0; j < LOG; j++) {
        int any_or_0 = 0;
        int any_and_1 = 0;
        for (int i = 1; i < n; i++) {
            if (!((1 << j) & OR[i])) {
                any_or_0 = 1;
            }
            if ((1 << j) & AND[i]) {
                any_and_1 = 1;
            }
        }
        int bit = -1;
        if (any_or_0) {
            bit = 0;
        } else if (any_and_1) {
            bit = 1;
        } else {
            bit = (hlp_or >> j) & 1;
            bit ^= 1;
        }
        a[0] |= bit << j;
    }
    for (int i = 1; i < n; i++)
        a[i] = a[0] ^ XOR[i];

    sort(a.begin(), a.end());
    finish(a[k - 1]);

//    for (auto x : a)
//        cout << x << " ";
//    cout << "\n";

    return 0;
}