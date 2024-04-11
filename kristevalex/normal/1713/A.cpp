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
#define log(x) cout << "logging: value of '" << #x << "' = " << x << "." << endl


vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;


int solve()
{
    cin >> n;
    int mn1 = 0, mx1 = 0;
    int mn2 = 0, mx2 = 0;
    int mn3 = 0, mx3 = 0;
    int mn4 = 0, mx4 = 0;

    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        if (x == 0)
        {
            if (y > 0)
            {
                mx1 = max(mx1, y);
            }
            else
                mx2 = max(mx2, -y);
        }
        else
        {
            if (x > 0)
            {
                mx3 = max(mx3, x);
            }
            else
                mx4 = max(mx4, -x);
        }
    }



cout << (mx1 + mx2+mx3+mx4)*2 << endl;

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