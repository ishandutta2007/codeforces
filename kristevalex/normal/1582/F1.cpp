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



long long a, b, k, n, tmp, ans = 0;



int solve()
{
    cin >> n;

    vi xorr(512, 1000);
    xorr[0] = 0;


    for (int i = 0; i < n; ++i)
    {
        int m;
        cin >> m;

        vi xor_ = xorr;

        for (int i = 0; i < 512; ++i)
        {
            if (xorr[i] < m)
            {
                xor_[i^m] = min(xor_[i^m], m);
            }
        }

        xorr = xor_;
    }

    vi anss;
    for (int i = 0; i < 512; ++i)
    {
        if (xorr[i] != 1000)
            anss.pb(i);
    }






    cout << anss.size() << endl;
    for (int i = 0; i < anss.size(); ++i)
    {
        cout << anss[i] << " ";
    }
    cendl;

    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}