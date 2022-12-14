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


vector<vi> data(300000, vi(20, 0));

long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    int l, r;
    cin >> l >> r;

    ans = 1000000;

    for (int i = 0; i < ::data[0].size(); ++i)
    {
        ans =min(::data[r][i] - ::data[l-1][i], (int)ans);
    }




    cout << ans << endl;

    return 0;
}


int main()
{
    FAST;

    for (int i = 1; i < ::data.size(); ++i)
    {
        for (int j = 0; j < ::data[0].size(); ++j)
        {
            ::data[i][j] = ::data[i-1][j];
            if ((i & (1<<j)) == 0)
                ::data[i][j]++;
        }
    }

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}