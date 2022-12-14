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
        x += other.x;
        if (x >= m) x -= m;

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
        tmp += other;
        return tmp;
    }

    modint operator- (const modint& other) const
    {
        modint tmp = *this;
        tmp -= other;
        return tmp;
    }

    modint operator* (const modint& other) const
    {
        modint tmp = *this;
        tmp *= other;
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

const int INF = 1200000000;



int solve()
{
    cin >> n;
    vi data(n);

    for (int i = 0; i < n; ++i)
        cin >> data[i];

    mint dp[2] = {mint(1), mint(0)};
    mint sum[2] = {mint(0), mint(0)};
    stack<pair<int, mint>> stk[2];
    stk[0].push({INF, mint(0)});
    stk[1].push({INF, mint(0)});

    for (int i = 0; i < n; ++i)
    {
        stk[0].push({data[i], mint(dp[0])});
        stk[1].push({data[i], mint(dp[1])});

        sum[0] += dp[0]*mint(data[i]);
        sum[1] += dp[1]*mint(data[i]);

        for (int j = 0; j < 2; ++j)
        {
            while (stk[j].size() >= 2)
            {
                auto last = stk[j].top();
                stk[j].pop();
                auto pre = stk[j].top();

                if (pre.ft >= last.ft)
                {
                    stk[j].pop();

                    sum[j] -= pre.sd * mint(pre.ft - last.ft);

                    pre.ft = last.ft;
                    pre.sd += last.sd;
                    stk[j].push(pre);
                }
                else
                {
                    stk[j].push(last);
                    break;
                }
            }
        }

        dp[0] = sum[1];
        dp[1] = sum[0];
    }

    cout << (dp[n%2] - dp[(n+1)%2]).x << endl;

    return 0;
}


int main()
{
    FAST;

    solve();

    return 0;
}