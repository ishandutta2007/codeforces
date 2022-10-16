#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int ds[maxn];

int root(int a){
    return ds[a] < 0 ? a : ds[a] = root(ds[a]);
}

bool join(int a, int b){
    a = root(a), b = root(b);
    if (a == b) return false;
    if (ds[a] < ds[b]) swap(a, b);
    ds[b] += ds[a];
    ds[a] = b;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("test.in", "r", stdin);
#endif

    int n, m, w;
    cin >> n >> m >> w;

    vector<int> dp(w + 1);

    vector<int> W(n), B(n);

    for (int i = 0; i < n; ++i) cin >> W[i];
    for (int i = 0; i < n; ++i) cin >> B[i];
    for (int i = 0; i < n; ++i) ds[i] = -1;

    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        join(u - 1, v - 1);
    }

    vector<int> TW(n), TB(n);
    vector<pii> G(n);

    for (int i = 0; i < n; ++i){
        G[i] = pii(root(i), i);
        TW[root(i)] += W[i];
        TB[root(i)] += B[i];
    }

    sort(G.begin(), G.end());

    for (int i = 0, j; i < n; i = j){
        for (int k = w - 1; k >= 0; --k){
            for (j = i; j < n && G[j].first == G[i].first; ++j){
                int u = G[j].second;

                if (k + W[u] <= w)
                    dp[ k + W[u] ] = max(dp[k + W[u]], dp[k] + B[u]);
            }
            int r = G[i].first;
            if (k + TW[r] <= w)
                dp[k + TW[r]] = max(dp[k + TW[r]], dp[k] + TB[r]);
        }
    }


    cout << dp[w] << endl;

    return 0;
}