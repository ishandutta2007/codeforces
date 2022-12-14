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


vector<pii> data;

long long a, b, k, n, m, tmp, ans = 0;

bool Check(int m1)
{
    int m_ = m1;
    int bef = 0;
    for (int i = 0; i < n; ++i)
    {
        if (::data[i].sd >= bef)
            if (::data[i].ft >= m1-1)
            {
                --m1;
                ++bef;
            }
    }

    if (bef >= m_)
        return true;
    else
        return false;
}

int solve()
{
    cin >> n;

    ::data.resize(n);

    for (int i = 0; i < n; ++i)
        cin >> ::data[i].ft >> ::data[i].sd;


    int l = 0;
    int r = n+1;
    while(r  - l > 1)
    {
        int m = (l+r)/2;
        if (Check(m))
            l = m;
        else
            r = m;
    }

    cout << l << endl;

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