#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

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

const int MOD = 998244353;
typedef modint<MOD> mint;


mint dp[1005][2005][4] = {};

mint anser(0);

int main()
    {
    FAST;


    cin >> n >> k;


    dp[0][1][0] = mint(1);
    dp[0][2][1] = mint(1);
    dp[0][2][2] = mint(1);
    dp[0][1][3] = mint(1);


    for (int i = 0; i <= n; i++)
        {
        for (int j = 1; j <= k; j++)
            {
            for (int bmask = 0; bmask < 4; bmask++)
                {
                //cout << "i: " << i << ", j: " << j << ", bmask: " << bmask << ", value: " << dp[i][j][bmask].x << endl;

                for (int bmask_new = 0; bmask_new < 4; bmask_new++)
                    {
                    int counter_new = 2;

                    if (bmask_new == 3 || bmask_new == 0) {counter_new--; /*cout << 1;*/}
                    if ((bmask_new & 1) == (bmask & 1)) {counter_new--; /*cout << 2;*/}
                    if ((bmask_new & 2) == (bmask & 2)) {counter_new--; /*cout << 3;*/}

                    if (counter_new < 0) counter_new = 0;

                    dp[i+1][j+counter_new][bmask_new]+= dp[i][j][bmask];
                    //cout << "adding to i: " << i+1 << ", j: " << j+counter_new << ", bmask: " << bmask_new << endl;//", value: " << dp[i][j][bmask].x << endl;

                    }
                }
            }
        }


    for (int i = 0; i < 4; i++)
        {
        anser+= dp[n-1][k][i];
        }

    cout << anser.x;

    return 0;
    }