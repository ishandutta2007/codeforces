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


long long a, b, k, n, m, tmp, ans = 0;



int solve()
{



    vector<string> data(2);

    cin >> data[0];
    cin >> data[1];
    n = data[0].size();
    m = data[1].size();

    vector<vector<vector<mint>>> dp(n+1, vector<vector<mint>>(m+1, vector<mint>(2, mint(0))));

    dp[0][1][1] = mint(1);
    dp[1][0][0] = mint(1);

    mint as(0);

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (i+j < 2) continue;
            for (int fl = 0; fl < 2; ++fl)
            {
                if (fl == 0 && i == 0)
                    continue;
                if (fl == 1 && j == 0)
                    continue;

                dp[i][j][fl] = mint(1);

                char sym;
                if (fl == 0)
                    sym = data[fl][i-1];
                else
                    sym = data[fl][j-1];

                int pi = i;
                int pj = j;
                if (fl == 0)
                    --pi;
                else
                    --pj;

                if (pi > 0)
                {
                    char ntsym = data[0][pi-1];
                    if (ntsym != sym)
                    {
                        dp[i][j][fl] += dp[pi][pj][0];
                    }
                }

                if (pj > 0)
                {
                    char ntsym = data[1][pj-1];
                    if (ntsym != sym)
                    {
                        dp[i][j][fl] += dp[pi][pj][1];
                    }
                }
                as += dp[i][j][fl];
            }

            //log(i);
            //log(j);
            //log(dp[i][j][0].x);
            //log(dp[i][j][1].x);
            //cendl;
        }
    }


    //cout << as.x << endl;

    for (int fl = 0; fl < 2; ++fl)
    {
        mint cur(1);
        as -= cur*mint(data[1-fl].size()+1);
        for (int i = 1; i < data[fl].size(); ++i)
        {
            if (data[fl][i] != data[fl][i-1])
                cur += mint(1);
            else
                cur = mint(1);

            as -= cur*mint(data[1-fl].size()+1);
            //log((cur*mint(data[1-fl].size()+1)).x);
        }
    }

    as+=mint(2);

    cout << as.x << endl;




    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}