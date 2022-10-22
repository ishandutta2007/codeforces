#include <bits/stdc++.h>
#define int long long
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()

const int N = (1<<20);
const int mod = 1e9+7;

int t, n, m, a[N], b[N], l[N], r[N];
int sma[N];
vector<int> ati[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }
        for (int i=1; i<=n; i++) {
            cin >> b[i];
            a[i] -= b[i];
        }
        for (int i=0; i<=n; i++) {
            ati[i].clear();
        }
        for (int i=0; i<m; i++) {
            cin >> l[i] >> r[i];
            ati[l[i]-1].push_back(i);
            ati[r[i]].push_back(i);
        }
        sma[0] = 0;
        for (int i=1; i<=n; i++) {
            sma[i] = sma[i-1] + a[i];
        }

        set<int> st;
        queue<int> q;
        for (int i=0; i<=n; i++) {
            if (sma[i] == 0) {
                for (int x : ati[i]) {
                    q.push(x);
                }
            } else {
                st.insert(i);
            }
        }

        while (!q.empty()) {
            int i = q.front(); q.pop();
            if (sma[l[i]-1] != 0 || sma[r[i]] != 0) {
                continue;
            }
            while (true) {
                auto it = st.lower_bound(l[i]);
                if (it == st.end()) {
                    break;
                }
                int j = *it;
                if (j > r[i]) {
                    break;
                }
                sma[j] = 0;
                st.erase(j);
                for (int x : ati[j]) {
                    q.push(x);
                }
            }
        }

        cout << (st.empty() ? "YES" : "NO") << endl;
    }
}