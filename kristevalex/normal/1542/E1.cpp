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
int m;
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

int MOD;
#define mint modint


int offset;

long long a, b, k, n, tmp;

inline int arc(int val)
{
    return val+offset;
}

inline int unarc(int val)
{
    return val-offset;
}



int solve()
{
    cin >> n >> m;
    offset = n * (n-1) / 2;



    mint ans(0);

    vector<mint> data(2*offset+3, mint(0));
    /*for (int i = 0; i < data.size(); ++i)
    {
        cout << data[i] << " ";
    }*/
    data[arc(0)] = mint(1);

    vector<mint> data_(2*offset+3, mint(0));

    //cout << "data size " << data.size() << endl;
    for (int ilen = 1; ilen < n-1; )
    {
        data_ = data;
        for (int i = 0; i < data.size(); ++i)
        {
            data[i] = mint(0);

                //cout << "+" << unarc(i) << endl;

            for (int j = -ilen; j <= ilen; ++j)
            {
                if (i + j < 0 || i + j >= data.size())
                    continue;

                mint mult(ilen + 1 - abs(j));



                if (data_[i+j].x > 0)

                    //cout << "+= " << (data_[i+j] * mult).x <<" (" << (data_[i+j] ).x <<"*" << (mult).x<<")"<< endl;


                data[i] += data_[i+j] * mult;
            }
        }

        /*for (int i = arc(0); i < arc(0)+10 && i < data.size(); ++i)
        {
            cout << data[i].x << " ";
        }
        cendl;*/

        ilen++;

        mint anscur(0);
        mint C(1);

        for (int i = n; ilen < i-1; --i)
        {
            C *= mint(i);
        }
        for (int i = 0; i < data.size(); ++i)
        {
            data_[i] = 0;
            for (int j = 1; j <= ilen; ++j)
            {
                if (i + j < 0 || i + j >= data.size())
                    continue;

                mint mult(ilen + 1 - abs(j));

                data_[i] += data[i+j] * mult;
            }
        }
        for (int i = arc(1); i < data_.size(); ++i)
        {
            anscur += data_[i];
        }
        ans += anscur * C;
    }




    cout << ans.x << endl;


    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}