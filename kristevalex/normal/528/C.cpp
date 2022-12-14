#include <vector>
#include <stack>
#include <algorithm>

struct EulerianTrail
{
    std::vector<std::vector<std::pair<int, int>>> g;
    std::vector<std::pair<int, int>> es;
    int M;
    std::vector<int> used_vertex, used_edge, deg;

    explicit EulerianTrail(int V) : g(V), M(0), deg(V), used_vertex(V) {}

    void add_edge(int a, int b)
    {
        es.emplace_back(a, b);
        g[a].emplace_back(b, M);

        g[b].emplace_back(a, M);
        deg[a]++;
        deg[b]++;

        M++;
    }

    std::pair<int, int> get_edge(int idx) const
    {
        return es[idx];
    }

    std::vector<std::vector<int>> enumerate_eulerian_trail()
    {
        for(auto &p : deg) if(p & 1) return {};

        used_edge.assign(M, 0);
        std::vector<std::vector<int>> ret;
        for(int i = 0; i < (int) g.size(); i++)
        {
            if(g[i].empty() || used_vertex[i]) continue;
            ret.emplace_back(enumerate_eulerian_trail_in_component(i));
        }
        return ret;
    }

    std::vector<int> enumerate_eulerian_trail_in_component(int s)
    {
        std::stack<std::pair<int,int>> st;
        std::vector<int> ord;
        st.emplace(s, -1);

        while (!st.empty())
        {
            int idx = st.top().first;
            used_vertex[idx] = true;

            if (g[idx].empty())
            {
                ord.emplace_back(st.top().second);
                st.pop();
            }
            else
            {
                auto e = g[idx].back();
                g[idx].pop_back();
                if(used_edge[e.second]) continue;
                used_edge[e.second] = true;
                st.emplace(e);
            }
        }
        ord.pop_back();
        std::reverse(ord.begin(), ord.end());
        return ord;
    }

    std::vector<int> GetEuler(int start = 0) // returns sequence of vertices in the component of vertex 'start'
    {
        std::vector<int> v = enumerate_eulerian_trail()[0];

        auto build = [&](int init) -> std::vector<int>
        {
            std::vector<int> ret;
            int now = init;
            for (auto ie : v)
            {
                ret.emplace_back(now);
                if (now != es[ie].first and now != es[ie].second) return {};
                now = now ^ es[ie].first ^ es[ie].second;
            }
            return ret;
        };

        std::vector<int> ret1 = build(es[v[0]].first);
        std::vector<int> ret2 = build(es[v[0]].second);
        if (ret1.empty())
            return ret2;
        return ret1;
    }
};
#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vpii = vector<pii>;
using vpll = vector<pll>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define psum(x) ((x).first + (x).second)
#define ft first
#define sd second
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define log(x) cout << "logging: value of '" << #x << "' = " << x << "." << endl


long long a, b, k, n, m, tmp, ans = 0;




int solve()
{
    cin >> n >> m;
    k = m;

    EulerianTrail et(n);

    vector<int> g(n);

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u]++;
        g[v]++;
        et.add_edge(u, v);
    }

    vi odds;
    for (int i = 0; i < n; ++i)
    {
        if (g[i]%2 == 1)
            odds.pb(i);
    }

    for (int i = 0; i < odds.size(); i += 2)
    {
        ++k;
        et.add_edge(odds[i], odds[i+1]);
    }

    if (k%2)
    {
        et.add_edge(0, 0);
    }


    vi order = et.GetEuler();
    cout << order.size() << '\n';
    for (int i = 1; i <= order.size(); ++i)
    {
        if (i%2)
            cout << order[i%order.size()] + 1 << ' ' << order[i-1] + 1 << '\n';
        else
            cout << order[i-1] + 1 << ' ' << order[i%order.size()] + 1 << '\n';
    }


    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}