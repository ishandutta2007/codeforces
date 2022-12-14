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

std::vector<mint> factorial;
std::vector<mint> invfactorial;
std::vector<mint> pow2;

inline mint C(int N, int K)
{
    if (N < K || K < 0)
        return mint();

    return factorial[N] * invfactorial[K] * invfactorial[N-K];
}

inline void SetupFactorial(int sz)
{
    ++sz;
    ::pow2.resize(sz);

    ::pow2[0] = 1;
    for (int i = 1; i < sz; ++i)
    {
        ::pow2[i] = ::pow2[i-1] * mint(2);
    }
}

vector<long long> data;

long long k, n, m, ans = 0;



int solve()
{
    SetupFactorial(1000002);

    cin >> n >> m >> k;

    vector<pii> rows(n, {0, 0});
    vector<pii> cols(m, {0, 0});
    pii totalerr = {0, 0};
    pii rowerr = {0, 0};
    int rowleft = n;
    pii colerr = {0, 0};
    int colleft = m;
    map<pii, int> mp;

    int a, b, tmp;

    for (int i = 0; i < k; ++i)
    {
        if (i > 300000)
            return 0;

        cin >> a >> b >> tmp;

        --a;
        --b;

        int oldvl = -1;
        if (/*k < 10 && */mp.count({a, b}) != 0)
            oldvl = mp[{a, b}];

        if (oldvl != -1)
        {
            if ((a+b+oldvl)%2 == 0)
                totalerr.ft--;
            else
                totalerr.sd--;


            if ((b+oldvl)%2 == 0)
            {
                rows[a].ft--;
                if (rows[a].ft == 0 && rows[a].sd == 0)
                    rowerr.sd--;
                else if (rows[a].ft == 0)
                    rowerr.ft--;
            }
            else
            {
                rows[a].sd--;
                if (rows[a].ft == 0 && rows[a].sd == 0)
                    rowerr.sd--;
                else if (rows[a].sd == 0)
                    rowerr.ft--;
            }
            if (rows[a].ft == 0 && rows[a].sd == 0)
                rowleft++;



            if ((a+oldvl)%2 == 0)
            {
                cols[b].ft--;
                if (cols[b].ft == 0 && cols[b].sd == 0)
                    colerr.sd--;
                else if (cols[b].ft == 0)
                    colerr.ft--;
            }
            else
            {
                cols[b].sd--;
                if (cols[b].ft == 0 && cols[b].sd == 0)
                    colerr.sd--;
                else if (cols[b].sd == 0)
                    colerr.ft--;
            }
            if (cols[b].ft == 0 && cols[b].sd == 0)
                colleft++;



        }

        if (tmp != -1)
        {
            if ((a+b+tmp)%2 == 0)
                totalerr.ft++;
            else
                totalerr.sd++;


            if (rows[a].ft == 0 && rows[a].sd == 0)
                rowleft--;
            if ((b+tmp)%2 == 0)
            {
                rows[a].ft++;
                if (rows[a].ft == 1 && rows[a].sd == 0)
                    rowerr.sd++;
                else if (rows[a].ft == 1)
                    rowerr.ft++;
            }
            else
            {
                rows[a].sd++;
                if (rows[a].ft == 0 && rows[a].sd == 1)
                    rowerr.sd++;
                else if (rows[a].sd == 1)
                    rowerr.ft++;
            }



            if (cols[b].ft == 0 && cols[b].sd == 0)
                colleft--;
            if ((a+tmp)%2 == 0)
            {
                cols[b].ft++;
                if (cols[b].ft == 1 && cols[b].sd == 0)
                    colerr.sd++;
                else if (cols[b].ft == 1)
                    colerr.ft++;
            }
            else
            {
                cols[b].sd++;
                if (cols[b].ft == 0 && cols[b].sd == 1)
                    colerr.sd++;
                else if (cols[b].sd == 1)
                    colerr.ft++;
            }
        }

        if (tmp == -1/* && k < 10*/)
            mp.erase({a, b});
        else/* if (k < 10)*/
            mp[{a, b}] = tmp;

        mint as(0);

        //cout << totalerr.ft << " " << totalerr.sd <<", " << rowerr.ft << " " << rowerr.sd << ", " << colerr.ft << " " << colerr.sd << endl;
        //cout << rowleft <<" " << colleft<<endl;
        if (totalerr.ft == 0)
            as -= mint(1);
        if (totalerr.sd == 0)
            as -= mint(1);

        if (rowerr.ft == 0)
            as += pow2[rowleft];

        if (colerr.ft == 0)
            as += pow2[colleft];

        cout << as.x << endl;
        //cendl;
    }


    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}