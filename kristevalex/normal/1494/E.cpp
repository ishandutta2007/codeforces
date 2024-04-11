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


vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> n >> k;

    set<pii> any;
    set<pii> same;
    set<pair<pii, char>> edges;

    while(k--)
    {
        //log(k);
        char c;
        cin >> c;
        if (c == '+')
        {
            int u, v;
            char val;
            cin >> u >> v >> val;

            edges.insert({{u, v}, val});

            auto it = edges.lower_bound({{v, u}, 'a' - 2});
            if (it != edges.end())
            {
                pii inv = {v, u};
                if (it->ft == inv)
                {
                    any.insert({u, v});
                    any.insert({v, u});

                    if (it->sd == val)
                    {
                        same.insert({u, v});
                        same.insert({v, u});
                    }
                }
            }
        }
        else if (c == '-')
        {
            int u, v;
            cin >> u >> v;

            auto it = edges.lower_bound({{u, v}, 'a' - 2});
            edges.erase(it);

            any.erase({u, v});
            any.erase({v, u});
            same.erase({u, v});
            same.erase({v, u});
        }
        else
        {
            int x;
            cin >> x;
            x %= 2;
            if (x == 0)
            {
                if (same.empty())
                    cno;
                else
                    cyes;
            }
            else
            {
                if (any.empty())
                    cno;
                else
                    cyes;
            }
        }
    }

    return 0;
}


int main()
{
    FAST;
        solve();

    return 0;
}