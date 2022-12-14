#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)


vector<long long> _data;

long long a, q, b, k, l, r, n, m, tmp, ans = 0;


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



int get_ans(int x, int y)
    {
    if (x == 0) return 0;

    mint
    ansx(2);
    ansx = ansx^(x);
    ansx--;



    if (y == 0)
        {
        return ansx.x;
        }



    mint ansy (2);
    ansy = ansy^(y);
    ansy--;

    ansy*= ansx;
    ansy+= ansx;

    return ansy.x;
    }



int main()
    {
    FAST;


    cin >> n >> q;

    string text;
    cin >> text;
    _data.resize(n+1);



    _data[0] = 0;
    for (int i = 1; i <= n; i++)
        {
        _data[i] = _data[i-1] + (text[i-1] - '0');
        }


    for (int i = 0; i < q; i++)
        {
        cin >> l >> r;
        --l;


        int num = _data[r] - _data[l];
        int dist = r - l;


        cout << get_ans(num, dist-num) << "\n";
        }





    return 0;
    }