#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int> vi;

const int64 oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

struct union_find{
    vector<int> D;

    union_find(int n){
        D = vi(n, -1);
    }

    int root(int a){
        return D[a] < 0 ? a : D[a] = root(D[a]);
    }

    void join(int a, int b){
        a = root(a), b = root(b);
        if (a == b) return;
        if (D[a] < D[b]) swap(a, b);
        D[b] += D[a];
        D[a] = b;
    }
};

// same code

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<union_find> U(m + 1, union_find(n + 1));

    for (int i = 0; i < m; ++i){
        int u, v, c;
        cin >> u >> v >> c;

        U[c].join(u, v);
    }

    int q; cin >> q;

    while (q--){
        int u, v; cin >> u >> v;

        int answer = 0;

        for (int i = 1; i <= m; ++i)
            if (U[i].root(u) == U[i].root(v))
                answer++;

        cout << answer << endl;
    }

    return 0;
}