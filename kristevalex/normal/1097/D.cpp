#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)


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


vector<long long> data;

long long a, b, k, n, m, tmp;


mint _count(long long base, int times)
    {
    vector<mint> one_n (times+2);

    for (int i = 1; i <= times+1; i++)
        {
        mint l (i);


        //cout << "one_n " << i << " " << l.x << endl;

        one_n[i] = l.inv();

        //cout << "one_n " << i << " " << one_n[i].x << endl;
        }


    vector<mint> dp (times+1);
    for (int i = 0; i < times+1; i++)
        {
        dp[i] = 0;
        }
    dp[times] = 1;

    for (int i = 0; i < k; i++)
        {
        mint update(0);
        mint update_new(0);

        for (int j = times; j >= 0; --j)
            {
            dp[j]*= one_n[j+1];


            update_new = update + dp[j];

            dp[j]+= update;

            update = update_new;
            }
        }


    mint ret(0);
    mint cur(1);
    for (int i = 0; i < times+1; i++)
        {
        ret+= dp[i]*cur;

        //cout << dp[i].x << " ";

        cur*= base;
        }

    cout << endl;

    return ret;
    }


int main()
    {
    FAST;


    cin >> n >> k;

    mint ans (1);

    long long SQRT = sqrt(n);

    for (int i = 2; i <= SQRT; i++)
        {
        if (n%i == 0)
            {
            int cnt = 0;
            while (n%i == 0)
                {
                n/= i;
                ++cnt;
                }

            ans*= _count(i, cnt);
            }
        }

    if (n > 1)
        ans*= _count(n, 1);


    cout << ans.x;

    return 0;
    }