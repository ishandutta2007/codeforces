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



long long a, b, k, n, m, tmp, ans = 0;

vector<int> primeNums;
vpii data;


int mebious(int val)
{
    int retnum = 0;
    int SQRT = sqrt(val) + 2;
    for (int i = 0; ::primeNums[i] < SQRT; ++i)
    {
        if (val % (::primeNums[i] * ::primeNums[i]) == 0)
            return 0;
        if (val % ::primeNums[i] == 0)
        {
            val /= ::primeNums[i];
            retnum++;
        }
    }

    if (val > 1)
        retnum++;

    if (retnum % 2 == 0)
        return 1;
    return -1;
}

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


mint GetAns(int d)
{
    vpii curdata = ::data;
    int curm = m / d;
    for (int i = 0; i < n; ++i)
    {
        curdata[i].ft += d-1;
        curdata[i].ft /= d;
        curdata[i].sd /= d;

        //cout << d << "'"  << i << ": " << curdata[i].ft << " " << curdata[i].sd << endl;
        if (curdata[i].sd < curdata[i].ft)
            return mint(0);
    }

    vector<mint> dp(curm+1);
    vector<mint> dp_prefs(curm+2);
    for (int i = 0; i < curm+1; ++i)
    {
        dp[i] = mint(0);
    }
    dp[0] = mint(1);

    for (int id = 0; id < n; ++id)
    {
        dp_prefs[0] = mint(0);
        for (int i = 0; i <= curm; ++i)
        {
            dp_prefs[i+1] = dp_prefs[i] + dp[i];
        }

        /*if (d == 1)
        {
            cout << "prefs " << endl;

            for (int i = 0; i < dp_prefs.size(); ++i)
            {
                cout << dp_prefs[i].x << " ";
            }

            cendl;
        }*/
        for (int i = curm; i >= 0; --i)
        {
            int mn = max(i - curdata[id].sd, 0);
            int mx = max(i - curdata[id].ft, -1);

            dp[i] = dp_prefs[mx+1] - dp_prefs[mn];
        }


        /*if (d == 1)
        {
            cout << "dp " << endl;


            for (int i = 0; i < dp.size(); ++i)
            {
                cout << dp[i].x << " ";
            }

            cendl;
            cendl;
        }*/


    }

    mint curans(0);
    for (int i = 0; i < dp.size(); ++i)
    {
        curans += dp[i];
    }

    return curans;
}



int solve()
{
    cin >> n >> m;

    vector<char> prime (100007, true);
    prime[0] = prime[1] = false;
    for (int i=2; i < prime.size(); ++i)
        if (prime[i])
        {
            if (i * 1ll * i < prime.size())
                for (int j=i*i; j < prime.size(); j+=i)
                    prime[j] = false;

            ::primeNums.pb(i);
        }

    ::data.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> ::data[i].ft >> ::data[i].sd;
    }




    mint anss(0);

    for (int i = 1; i <= m; ++i)
    {
        int mebval = mebious(i);
        //cout << i << ": " << GetAns(i).x << endl;
        if (mebval != 0)
            anss += mint(mebval) * GetAns(i);
    }



    cout << anss.x;

    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}