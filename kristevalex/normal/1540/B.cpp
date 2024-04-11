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

template<int m>
struct modint
    {
    long long x;

    modint() :
        x(0) {}

    modint(long long arg)
        {
        arg%= m;
        if (arg < 0) x = arg + m;
        else x = arg;
        }

    modint& operator+= (const modint& other)
        {
        x+= other.x;
        if (x >= m) x-= m;

        return *this;
        }

    modint& operator*= (const modint& other)
        {
        x = (x * 1ll * other.x) % m;
        return *this;
        }

    modint& operator-= (const modint& other)
        {
        x+= m - other.x;
        if (x >= m) x-= m;

        return *this;
        }

    modint operator+ (const modint& other) const
        {
        modint tmp = *this;
        tmp+= other;
        return tmp;
        }

    modint operator- (const modint& other) const
        {
        modint tmp = *this;
        tmp-= other;
        return tmp;
        }

    modint operator* (const modint& other) const
        {
        modint tmp = *this;
        tmp*= other;
        return tmp;
        }

    explicit operator int () const
        {
        return x;
        }

    modint& operator++ ()
        {
        ++x;
        if (x == m) x = 0;

        return *this;
        }

    modint& operator-- ()
        {
        if (x == 0) x = m-1;
        else --x;

        return *this;
        }

    modint operator++ (int)
        {
        modint tmp = *this;
        ++*this;

        return tmp;
        }

    modint operator-- (int)
        {
        modint tmp = *this;
        --*this;

        return tmp;
        }

    bool operator== (const modint& other) const
        {
        return x == other.x;
        }

    bool operator!= (const modint& other) const
        {
        return x != other.x;
        }

    template<class T>
    modint operator^ (T arg) const
        {
        if (arg == 0) return 1;
        if (arg == 1) return x;

        auto t = *this ^ (arg >> 1);
        t*= t;

        if (arg & 1) t*= *this;

        return t;
        }

    modint inv() const // works clearly only when 'm' is prime number
        {
        return *this ^ (m-2);
        }
};

const int MOD = 1000000007;
typedef modint<MOD> mint;

mint inv_n;
mint inv_2;
mint ans(0);


vvi g;

vector<vector<mint>> dp;

long long a, b, k, n, m, tmp;

vpii dfs(int cur, int prev)
{
    vpii ret(1);
    ret[0] = {cur, 0};

    for (int id = 0; id < g[cur].size(); ++id)
    {
        int next = g[cur][id];
        if (next == prev)
            continue;

        auto nextVal = dfs(next, cur);
        for (int i = 0; i < nextVal.size(); ++i)
        {
            for (int j = 0; j < ret.size(); ++j)
            {
                pii p1 = nextVal[i];
                p1.sd++;
                pii p2 = ret[j];
                if (p1.ft > p2.ft)
                    {ans += dp[p2.sd][p1.sd]; /*cout << "adding[" << p2.sd<<"]["<<p1.sd << "]:= " << dp[p2.sd][p1.sd].x << endl;*/}
                else
                    {ans += dp[p1.sd][p2.sd]; /*cout << "adding[" << p1.sd<<"]["<<p2.sd << "]:= " << dp[p1.sd][p2.sd].x << endl;*/}
            }
        }

        for (int i = 0; i < nextVal.size(); ++i)
            ret.pb({nextVal[i].ft, nextVal[i].sd+1});
    }

    return ret;
}



int solve()
{
    cin >> n;
    inv_n = mint(n).inv();
    inv_2 = mint(2).inv();

    ::g.resize(n);

    for (int i = 0; i < n-1; ++i)
    {
        cin >> a >> b;
        --a;
        --b;
        g[a].pb(b);
        g[b].pb(a);
    }

    ::dp.resize(n+1);
    for (int i = 0; i <= n; ++i)
        ::dp[i].resize(n+1);

    for (int i = 1; i <= n; ++i)
        ::dp[i][0] = mint(1);

    for (int i = 0; i <= n; ++i)
        ::dp[0][i] = mint(0);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            ::dp[i][j] = (::dp[i-1][j] + ::dp[i][j-1])*inv_2;


    //cout << "hi!" << endl;

    //cout << ans.x << endl;
    for (int i = 0; i < n; ++i)
        {
            dfs(i, -1);
            //cout << ans.x << endl;
        }


    cout << (ans*inv_n).x << endl;

    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}