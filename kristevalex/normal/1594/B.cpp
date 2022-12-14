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

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define cendl cout << endl


vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;

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

int solve()
{
    cin >> n >> m;

    mint as (0);
    mint cur (1);
    mint m_ (n);

    while (m > 0)
    {
        if (m%2 == 1)
            {
                as+= cur;
                //cout << "c" <<cur.x << endl;
            }

        m/= 2;

        cur *= m_;
    }




    cout << as.x << endl;

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