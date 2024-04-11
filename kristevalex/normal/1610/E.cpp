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

long long a, b, k, n, m, tmp;


inline int GetMinId(int minVal)
{
    int l = -1;
    int r = ::data.size();

    while(r-l > 1)
    {
        int mid = (l+r)/2;
        if (::data[mid].ft >= minVal)
            r = mid;
        else
            l = mid;
    }

    return r;
}

inline int GetStartId(int startId)
{
    int startVal = ::data[startId].ft;
    int ans = 0;

    ans += ::data[startId].sd;

    int next = GetMinId(startVal+1);
    while(next < ::data.size())
    {
        ++ans;
        next = GetMinId(2*::data[next].ft - startVal);
    }

    return ans;
}

int solve()
{
    cin >> n;

    ::data.resize(0);

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (::data.size() == 0 || ::data[::data.size()-1].ft != x)
            ::data.pb({x, 1});
        else
            ::data[::data.size()-1].sd++;
    }

    int maxx = 0;
    for (int i = 0; i < ::data.size(); ++i)
    {
        maxx = max(maxx, GetStartId(i));
    }




    cout << n - maxx << endl;

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