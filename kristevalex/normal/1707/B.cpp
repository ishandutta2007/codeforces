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



long long a, b, k, n, m, tmp, ans = 0;

/*

1
4
4 8 9 13

*/

int solve()
{
    cin >> n;

    vi data;
    int zeros = 0;

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (x != 0)
            data.pb(x);
        else
            zeros++;
    }

    while(data.size() > 1)
    {
        /*log(data.size());
        log(zeros);
        for (int i = 0; i < zeros; ++i)
        {
            cout << 0 << ' ';
        }
        for (int i = 0; i < data.size(); ++i)
        {
            cout << data[i] << ' ';
        }*/
        vi nt;
        if(zeros > 0)
        {
            zeros--;
            nt.pb(data[0]);
        }
        for (int i = 1; i < data.size(); ++i)
        {

            if (data[i] == data[i-1])
                zeros++;
            else
                nt.pb(data[i] - data[i-1]);
        }
        sort(all(nt));

        //cendl;
        data = nt;
    }

    ans = 0;
    if (data.size() > 0)
        ans = data[0];


    ans = max(ans, 0ll);




    cout << ans << endl;

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