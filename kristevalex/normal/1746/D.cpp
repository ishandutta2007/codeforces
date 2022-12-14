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

template<typename T1, typename T2> ostream& operator<<(ostream& out, const pair<T1, T2>& x) {return out << x.first << ' ' << x.second;}
template<typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& x) {return in >> x.first >> x.second;}
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};


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

vector<map<int, ll>> cash;
vvi g;

long long a, b, k, n, m, tmp, ans = 0;


ll dfs(int cur, int prev, ll num)
{
    //log(cur);
    //log(prev);
    //log(num);

    if (cash[cur].count(num) > 0)
        return cash[cur][num];

    int sz = g[cur].size()-1;
    if (cur == 0)
        ++sz;

    if (sz == 0)
        return ::data[cur] * num;

    vl adds;

    ll nnum = num / sz;
    ll left = num - nnum*sz;

    ll as = 0;

    //log("hi");
    for (int i = 0; i < g[cur].size(); ++i)
    {
        int next = g[cur][i];
        //log(next);
        if (next == prev)
            continue;

        ll val = dfs(next, cur, nnum);
        as += val;
        if (left > 0)
        {
            ll val2 = dfs(next, cur, nnum+1);

            adds.pb(val2 - val);
        }
    }

    sort(all(adds));
    reverse(all(adds));
    for (int i = 0; i < left; ++i)
    {
        as += adds[i];
    }

    cash[cur][num] = as + num * ::data[cur];

    return as + num * ::data[cur];
}



int solve()
{
    cin >> n >> k;

    g.assign(n, vi());
    cash.assign(n, map<int, ll>());

    for (int i = 1; i < n; ++i)
    {
        cin >> tmp;
        --tmp;
        g[i].pb(tmp);
        g[tmp].pb(i);
    }


    ::data.resize(n);
    cin >> ::data;


    //log(g);
    //log(::data);

    cout << dfs(0, -1, k) << endl;

    return 0;
}


int main()
{
    FAST;

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}