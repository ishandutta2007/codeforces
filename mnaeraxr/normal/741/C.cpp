#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200010;

int to[maxn], m;
int col[maxn];

struct satisfiability_twosat
{
    int n;
    vector<vector<int>> imp;

    satisfiability_twosat(int n) : n(n), imp(2 * n) {}

    void add_edge(int u, int v)
    {
        imp[u].push_back(v);
    }

    int neg(int u) { return (n << 1) - u - 1; }

    void implication(int u, int v)
    {
        add_edge(u, v);
        add_edge(neg(v), neg(u));
    }

    void equal(int u, int v){
        implication(u, v);
        implication(v, u);
    }

    vector<bool> solve()
    {
        int size = 2 * n;
        vector<int> S, B, I(size);

        function<void(int)> dfs = [&](int u)
        {
            B.push_back(I[u] = S.size());
            S.push_back(u);

            for (int v : imp[u])
                if (!I[v]) dfs(v);
                else while (I[v] < B.back()) B.pop_back();

            if (I[u] == B.back())
                for (B.pop_back(), ++size; I[u] < S.size(); S.pop_back())
                    I[S.back()] = size;
        };

        for (int u = 0; u < 2 * n; ++u)
            if (!I[u]) dfs(u);

        vector<bool> values(n);

        for (int u = 0; u < n; ++u)
            if (I[u] == I[neg(u)]) return {};
            else values[u] = I[u] < I[neg(u)];

        return values;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("test.in", "r", stdin);
#endif

    int n; cin >> n;
    m = 2 * n;

    vector<pii> C(n);

    satisfiability_twosat sat(n);

    for (int i = 0; i < n; ++i){
        int u, v; cin >> u >> v;
        u--; v--;
        C[i] = pii(u, v);

        int uu = u / 2;
        int vv = v / 2;

        if ((u & 1) == (v & 1))
            sat.equal(uu, sat.neg(vv));
        else
            sat.equal(uu, vv);
    }

    auto ans = sat.solve();

    if (ans.empty()) cout << -1 << endl;
    else{
        for (int i = 0; i < n; ++i)
            if (ans[i]) col[2 * i] = 1, col[2 * i + 1] = 2;
            else col[2 * i] = 2, col[2 * i + 1] = 1;

        for (int i = 0; i < n; ++i)
            cout << col[ C[i].first ] << " " << col[ C[i].second ] << endl;
    }

    return 0;
}