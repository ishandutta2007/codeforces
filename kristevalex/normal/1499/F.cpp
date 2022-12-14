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

const int MOD = 998244353;
typedef modint<MOD> mint;




vvi g;

long long a, b, k, n, m, tmp, ans = 0;

using vmint = vector<mint>;

inline vector<mint> mr(const vector<mint>& x, const vector<mint>& y)
{
    vmint x_(k+2);
    vmint y_(k+2);
    for (int i = 0; i <= k; ++i)
    {
        x_[i+1] = x_[i] + x[i];
        y_[i+1] = y_[i] + y[i];
    }

    vmint ret = x;
    for (int i = 0; i <= k; ++i)
    {
        ret[i] *= y_[k+1];
    }
    for (int i = 0; i <= k; ++i)
    {
        int othery = min((ll)i-1ll, k-1-i);
        ret[i] += x[i] * y_[othery+1];
    }
    for (int i = 0; i < k; ++i)
    {
        int otherx = min((ll)i, k-1-i);
        ret[i+1] += y[i] * x_[otherx+1];
    }


    //log("merge");
    /*for (int i = 0; i <= k; ++i)
    {
        cout << ret[i].x << " ";
    }
    cendl;*/
    return ret;
}

vmint dfs(int cur = 0, int prev = -1)
{
    vmint ret(k+1, mint(0));
    ret[0] = mint(1);

    for (int i = 0; i < ::g[cur].size(); ++i)
    {
        int next = ::g[cur][i];
        if (next != prev)
        {
            auto nres = dfs(next, cur);
            ret = mr(ret, nres);
        }
    }

    /*log(cur);
    log(prev);
    for (int i = 0; i <= k; ++i)
    {
        cout << ret[i].x << " ";
    }
    cendl;*/

    return ret;
}



int solve()
{
    cin >> n >> k;
    ::g.resize(n);


    for (int i = 0; i < n-1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        ::g[u].pb(v);
        ::g[v].pb(u);
    }


    auto rt = dfs();

    mint as(0);
    for (int i = 0; i <= k; ++i)
    {
        as += rt[i];
    }

    cout << as.x << endl;

    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}