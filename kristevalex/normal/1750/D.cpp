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
#define log(x) //cout << "logging: value of '" << #x << "' = " << x << "." << endl

template<int m>
struct modint
{
    int x;

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


vector<long long> data;

long long a, b, k, n, m, tmp;



int solve()
{
    cin >> n >> m;

    ::data.resize(n);
    cin >> ::data;

    mint ans(1);

    for (int i = 1; i < n; ++i)
    {
        log(i);
        if ((::data[i-1])%(::data[i]) != 0)
        {
            cout << 0 << '\n';
            return 0;
        }

        if (::data[i-1] == ::data[i])
        {
            ans *= (m / ::data[i]);
            continue;
        }

        ll tot = m / ::data[i];
        ll ban = ::data[i-1] / ::data[i];

        vi primes;
        int SQ = sqrt(ban);
        for (int j = 2; j <= SQ; ++j)
        {
            if (ban % j == 0)
            {
                primes.pb(j);
                while(ban % j == 0)
                    ban /= j;
            }
        }
        if (ban > 1)
            primes.pb(ban);

            log(primes);

        int ways = 0;

        int mx = (1 << primes.size());

        log(mx);
        log(tot);
        for (int mask = 0; mask < mx; ++mask)
        {
            int cnt = 0;
            int num = 1;
            for (int j = 0; j < primes.size(); ++j)
            {
                if (mask & (1<<j))
                {
                    ++cnt;
                    num *= primes[j];
                }
            }


            int curnum = tot / num;
            log(cnt);
            log(curnum);
            if (cnt%2 == 0)
                ways += curnum;
            else
                ways -= curnum;
        }

        log(ways);

        ans *= ways;
    }




    cout << ans.x << endl;

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