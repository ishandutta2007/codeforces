#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 105;

int n, m, ar[MAXN], cap[MAXN][MAXN], vs = MAXN-2, vt = MAXN-1;
bool good[MAXN][MAXN];
vector<int> vdiv[MAXN]; int pnt[MAXN];
set<int> primes;
bool vis[MAXN];

bool dfs(int cur) {
    if (cur == vt) return 1;
    if (vis[cur]) return 0;
    vis[cur] = 1;
    for (int i=0; i<MAXN; i++)
        if (cap[cur][i])
            if (dfs(i)) {
                cap[cur][i]--;
                cap[i][cur]++;
                return 1;
            }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> ar[i];
        int k = 2;
        while (ll(k)*k <= ar[i]) {
            if (ar[i]%k == 0) vdiv[i].push_back(k), primes.insert(k), ar[i]/=k;
            else k++;
        }
        if (ar[i]>1) vdiv[i].push_back(ar[i]), primes.insert(ar[i]);
    }
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (a%2) swap(a, b);
        good[a][b] = 1;
    }

    int ans = 0;
    for (typeof(primes.begin()) it=primes.begin(); it != primes.end(); it++) {
        int p = *it;
        memset(cap, 0, sizeof(cap));
        memset(vis, 0, sizeof(vis));
        for (int i=0; i<n; i++) {
            while (pnt[i]<vdiv[i].size() && vdiv[i][pnt[i]] == p) {
                if (i%2 == 0) cap[vs][i]++;
                else cap[i][vt]++;
                pnt[i]++;
            }
        }
        for (int i=0; i<n; i+=2)
            for (int j=1; j<n; j+=2)
                if (good[i][j])
                    cap[i][j] = 10000;

        while (dfs(vs)) {
            ans++;
            memset(vis, 0, sizeof(vis));
        }
    }

    cout << ans << '\n';
    return 0;
}