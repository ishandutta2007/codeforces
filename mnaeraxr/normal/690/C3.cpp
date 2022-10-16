#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200010;

int lca[maxn][20];
int h[maxn];

int get_lca(int u, int v){
    if (h[u] < h[v]) swap(u, v);
    int d = h[u] - h[v];

    for (int i = 0; d; i++){
        if (d >> i & 1){
            u = lca[u][i];
            d ^= 1 << i;
        }
    }

    if (u == v) return u;

    for (int i = 19; i >= 0; --i){
        if (lca[u][i] != lca[v][i])
            u = lca[u][i], v = lca[v][i];
    }

    return lca[u][0];
}

int dist(int u, int v){
    int l = get_lca(u, v);

    return h[u] + h[v] - 2 * h[l];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    int e1 = 1, e2 = 1, d = 0;

    for (int i = 2; i <= n; ++i){
        int v; cin >> v;

        h[i] = h[v] + 1;

        lca[i][0] = v;
        for (int j = 1; j < 20; ++j)
            lca[i][j] = lca[lca[i][j - 1]][j - 1];

        int d1 = dist(i, e1);
        int d2 = dist(i, e2);

        if (d2 > d){
            d = d2;
            e1 = i;
        }

        if (d1 > d){
            d = d1;
            e2 = i;
        }

        cout << d << " ";
    }

    cout << endl;

    return 0;
}