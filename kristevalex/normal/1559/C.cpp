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



long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> n;

    vi data(n);

    for (int i = 0; i < n; ++i)
        cin >> data[i];

    if (data[0] == 1)
    {
        cout << n+1 << " ";
        for (int i = 0; i < n; ++i)
        {
            cout << i+1 << " ";
        }
        cendl;
        return 0;
    }
    for (int i = 0; i < n-1; ++i)
    {
        if (data[i] == 0 && data[i+1] == 1)
        {
            for (int j = 0; j <= i; ++j)
            {
                cout << j+1 << " ";
            }
            cout << n+1 << " ";
            for (int j = i+1; j < n; ++j)
            {
                cout << j+1 << " ";
            }
            cendl;
            return 0;
        }
    }

    if (data[n-1] == 0)
    {
        //if (n > 100)

        //cout <<"hi" << data[n-1] << "j";
        for (int i = 0; i <= n; ++i)
        {
            cout << i+1 << " ";
        }
        cendl;
        return 0;
    }





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