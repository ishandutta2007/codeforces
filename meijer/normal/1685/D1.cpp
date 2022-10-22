#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()

const int N = (1<<20);
const int mod = 1e9+7;

int t, n, p[N], q[N], rp[N];
int vis[N], nxt[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=1; i<=n; i++)
            cin >> p[i];
        for (int i=1; i<=n; i++)
            rp[p[i]] = i;
        for (int i=1; i<=n; i++)
            nxt[i] = rp[i];
        fill(vis, vis+n+1, 0);
        for (int i=1; i<=n; i++) {
            if (vis[i]) continue;
            int u = i;
            do {
                vis[u] = 1, u = nxt[u];
            } while (u != i);
            if (i == 1) continue;
            nxt[i] = nxt[i-1];
            nxt[i-1] = rp[i];
        }

        int u = 1;
        do {
            cout << u << " ";
            u = nxt[u];
        } while (u != 1);
        cout << endl;
    }
}