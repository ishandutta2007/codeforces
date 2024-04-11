#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef complex<int64> point;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int64 cross(point a, point b){
    return imag(conj(a) * b);
}

int par[maxn][20];
int stk[maxn], top;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<point> V(n + 1);
    vector<int> D(n + 1);

    for (int i = 1; i <= n; ++i){
        int64 x, y; cin >> x >> y;
        V[i] = point(x, y);
    }

    for (int i = n; i; --i){
        while (top > 1 && cross(V[ stk[top - 1] ] - V[i], V[ stk[top - 2] ] - V[i]) > 0)
            top--;

        if (top){
            par[i][0] = stk[top - 1];
            D[i] = D[ par[i][0] ] + 1;
        }

        stk[top++] = i;
    }

    for (int i = 1; i < 20; ++i)
        for (int j = 1; j <= n; ++j)
            par[j][i] = par[ par[j][i - 1] ][i - 1];

    int q; cin >> q;

    while (q--){
        int u, v, a; cin >> u >> v;
        if (D[u] < D[v]) swap(u, v);

        int d = D[u] - D[v];

        for (int i = 0; d; ++i){
            if (d >> i & 1){
                d ^= 1 << i;
                u = par[u][i];
            }
        }

        if (u == v) a = u;
        else{
            for (int i = 19; ~i; --i){
                if (par[u][i] != par[v][i]){
                    u = par[u][i];
                    v = par[v][i];
                }
            }

            a = par[u][0];
        }

        cout << a << " ";
    }

    cout << endl;

    return 0;
}