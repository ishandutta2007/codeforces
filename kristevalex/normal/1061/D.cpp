#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

#define pii pair<long long ,long long>

vector<pii> data;

long long x, y, a, b, k, n, m, tmp;


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


mint ans;


int main()
    {
    //FAST;


    map<long long, int> Last;
    //Map[2]++;
    //Map.erase(2);
    //if (Map.upper_bound(1) == Map.end()) cout << "broken_pipe";

    cin >> n >> x >> y;

    data.resize(n);

    for (int i = 0; i < n; i++)
        cin >> data[i].first >> data[i].second;

    sort(data.begin(), data.end());

    for (int i = 0; i < n; i++)
        {
        auto it = Last.upper_bound(MOD - data[i].first);

        if (it != Last.end())
            {
            //cout << data[i].first << " hello " << data[i].first << " " <<  (MOD - it->first) << endl;

            if ((data[i].first - (MOD - it->first))*y <= x)
                {
                ans+= (data[i].second - (MOD - it->first))*y;
                --(Last[it->first]);
                if (Last[it->first] == 0) Last.erase(it);
                ++(Last[MOD - data[i].second]);
                continue;
                }
            }

        ans+= x + (data[i].second - data[i].first)*y;
        ++(Last[MOD - data[i].second]);
        }






    cout << ans.x;

    return 0;
    }