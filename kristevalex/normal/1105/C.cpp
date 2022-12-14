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

vector<mint> data0;
vector<mint> data1;
vector<mint> data2;

long long a, b, k, n, m, tmp, ans = 0, l, r;





int main()
    {
    FAST;


    cin >> n >> l >> r;
    --l;

    data0.resize(n);
    data1.resize(n);
    data2.resize(n);

    mint m0 (r/3 - l/3);
    mint m1 ((r+2)/3 - (l+2)/3);
    mint m2 ((r+1)/3 - (l+1)/3);

    data0[0] = m0;
    data1[0] = m1;
    data2[0] = m2;

    for (int i = 1; i < n; i++)
        {
        data0[i] = data0[i-1]*m0;
        data1[i] = data0[i-1]*m1;
        data2[i] = data0[i-1]*m2;

        data0[i]+= data1[i-1]*m2;
        data1[i]+= data1[i-1]*m0;
        data2[i]+= data1[i-1]*m1;

        data0[i]+= data2[i-1]*m1;
        data1[i]+= data2[i-1]*m2;
        data2[i]+= data2[i-1]*m0;
        }

    cout << data0[n-1].x;

    return 0;
    }