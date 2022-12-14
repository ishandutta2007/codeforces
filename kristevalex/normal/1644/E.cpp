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
    cin >> m;

    string s;
    cin >> s;

    n = s.size();

    for (int i = 0; i <= n; ++i)
    {
        if (i == n)
        {
            cout << m << endl;
            return 0;
        }

        if (s[i] != s[0])
            break;
    }

    s.pb('X');

    vl D(n+1, 0);
    vl R(n+1, 0);

    for (int i = n-1; i >= 0; --i)
    {
        D[i] = D[i+1];
        R[i] = R[i+1];

        if (s[i] == 'R')
            R[i]++;
        else
            D[i]++;
    }

    ans = 0;
    bool fase1 = true;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] != s[0]) fase1 = false;

        if (fase1)
        {
            ans += m-1;
        }
        else
        {
            if (s[i] == 'D')
                ans += R[i];
            else
                ans += D[i];
        }
    }

    //log(ans);




    cout << m*m - ans << endl;

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