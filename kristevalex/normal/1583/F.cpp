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


vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> n >> k;

    m = n;

    while (m > 1)
    {
        m = (m + k - 1)/k;
        ++ans;
    }

    cout << ans  << endl;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i+1; j <= n; ++j)
        {
            tmp = 0;
            a = i;
            b = j;

            while(a != b)
            {
                a = (a + k - 1)/k;
                b = (b + k - 1)/k;
                ++tmp;
            }
            cout << tmp << " ";
        }
    }


    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}