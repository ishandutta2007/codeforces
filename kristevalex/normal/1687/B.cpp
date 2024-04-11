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



int solve()
{
    cin >> n >> m;

    vpii data (m);
    for (int i = 0; i < m; ++i)
    {
        cout << "? ";
        for (int j = 0; j < m; ++j)
        {
            if (i == j) cout << '1';
            else cout << '0';
        }
        cendl;
        cin >> data[i].ft;
        data[i].sd = i;
    }
    sort(all(data));

    vector<char> as(m, '0');
    ans = 0;

    for (int i = 0; i < m; ++i)
    {
        int curid = data[i].sd;
        as[curid] = '1';

        cout << "? ";
        for (int j = 0; j < m; ++j)
            cout << as[j];
        cendl;

        ll curans;
        cin >> curans;

        if (curans - ans == data[i].ft)
        {
            ans = curans;
        }
        else
        {
            as[curid] = '0';
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