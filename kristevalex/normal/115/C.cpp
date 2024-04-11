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



long long a, b, k, n, m, tmp;

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

const int MOD = 1000003;
typedef modint<MOD> mint;

int solve()
{
    cin >> n >> m;
    mint ans(1);

    vector<string> data(n);

    for (int i = 0; i < n; ++i)
        cin >> data[i];


    vi top(m, 0);
    vi left(n, 0);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (data[i][j] != '.')
            {
                //cout <<  "hi "<< i <<", " << j << endl;
                int type = data[i][j] - '0';

                int l = 0;
                int t = 0;
                if (type == 1 || type == 2)
                    l = 1;
                if (type == 1 || type == 4)
                    t = 1;

                l += j;
                l %= 2;
                ++l;

                t += i;
                t %= 2;
                ++t;

                if (left[i] == 3 - l)
                {
                    ans = mint(0);
                }
                left[i] = l;
                //cout << "left " << left[i] << endl;


                if (top[j] == 3 - t)
                {
                    ans = mint(0);
                }
                top[j] = t;
                //cout << "top " << top[j] << endl;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        //cout << left[i] << " " ;
        if (left[i] == 0)
            ans *= mint(2);
    }
    //cendl;

    for (int i = 0; i < m; ++i)
    {
        //cout << top[i] << " " ;
        if (top[i] == 0)
            ans *= mint(2);
    }
    //cendl;



    cout << ans.x << endl;

    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}