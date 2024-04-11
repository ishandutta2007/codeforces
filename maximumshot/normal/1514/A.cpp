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

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int ok = 0;
        for (int x, i = 0; i < n; i++) {
            cin >> x;
            int p = 1;
            while (p * p < x)
                p++;
            if (p * p != x) {
                ok = 1;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}