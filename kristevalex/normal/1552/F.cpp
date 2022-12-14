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

const int MOD = 998244353;
typedef modint<MOD> mint;



long long a, b, k, n, m, tmp, ans = 0;

bool operator<(pair<int, mint> p1, pair<int, mint> p2)
{
    if (p1.ft == p2.ft)
        return p1.sd.x < p2.sd.x;
    return p1.ft < p2.ft;
}

int solve()
{
    cin >> n;

vector<pii> data(n);
vector<mint> dp(n);

    for (int i = 0; i < n; ++i)
        {
            int tmp1;
            cin >> data[i].ft >> data[i].sd >> tmp1;
            dp[i] = mint(tmp1);
        }

    multiset<pair<int, mint>> st;
    st.insert({-data[n-1].sd, dp[n-1]});
    mint cur_sum = dp[n-1];
    for (int i = n-2; i >= 0; --i)
    {
        while(!st.empty())
        {
            auto it = st.begin();
            if (-(it->ft) < data[i].ft)
                break;

            cur_sum -= it->sd;
            st.erase(it);
        }

        dp[i] += cur_sum;

        cur_sum += dp[i];
        st.insert({-data[i].sd, dp[i]});
    }

    mint anss(data[n-1].ft + 1);
    for (int i = 0; i < n; ++i)
    {//cout << dp[i].x << " ";
        anss += mint(data[i].ft - data[i].sd) * dp[i];
    }
    cout << endl;


/*
5
96 4 0
97 5 0
98 30 0
99 20 0
100 10 1

*/

    cout << anss.x << endl;

    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}