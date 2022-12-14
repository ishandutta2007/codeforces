#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<int> data;

int a, b, k, n, m, tmp;

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

#define pii pair<int,int>

int main()
    {
    FAST;


    cin >> n;

    data.resize(n);

    for (int i = 0; i < n; ++i)
        cin >> data[i];


    mint anser[1000007];
    anser[0]++;

    stack<pair<int, int>> St;

    for (int i = 0; i < n; ++i)
        {
        int SQRT = sqrt(data[i]);

        for (int j = 1; j <= SQRT; ++j)
            {
            if (data[i]%j == 0)
                {
                if (j*j == data[i])
                    {
                    //anser[j]+= anser[j-1];
                    St.push(pii(j, anser[j-1].x));
                    }
                else
                    {
                    int inv_ = data[i]/j;

                    St.push(pii(inv_, anser[inv_-1].x));
                    //anser[inv_]+= anser[inv_-1];

                    St.push(pii(j, anser[j-1].x));
                    //anser[j]+= anser[j-1];
                    }
                }
            }

        while(!St.empty())
            {
            pair<int, int> cur = St.top();
            St.pop();

            anser[cur.first]+= cur.second;
            }



        }

    mint ans;

    for (int i = 1; i < 100005; i++)
        {
        ans+= anser[i];
        }

    cout << ans.x;

    return 0;
    }