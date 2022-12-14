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

    int l = 0;
    int r = 10000000;
    while(r-l > 1)
    {
        int mid = (l+r)/2;
        cout << "? " << mid << endl;
        cin >> ans;
        if (ans == 1)
            r = mid;
        else
            l = mid;
    }
    l = r;

    int sum = l - n + 1;

    ans = l;

    for (int i = 1; i <= n; ++i)
    {
        int val = (l-1)/i;
        if (val < 1)
            continue;
        cout << "? " << val << endl;
        ll res;
        cin >> res;
        if (res > 0)
        {
            ans = min(ans, res * val);
        }
    }

    cout << "! " << ans << endl;



    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}