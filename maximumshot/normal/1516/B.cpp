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
        vector<int> a(n + 2);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector<int> pr(n + 2);
        for (int i = 1; i <= n; i++)
            pr[i] = pr[i - 1] ^ a[i];
        int ok = 0;
        for (int i = 1; i < n; i++) {
            if (pr[i] == (pr[n] ^ pr[i])) {
                ok = 1;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = i + 2; j <= n; j++) {
                int L = pr[i];
                int R = pr[n] ^ (pr[j - 1]);
                int M = L ^ R ^ pr[n];
                if (L == M && R == M) {
                    ok = 1;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}