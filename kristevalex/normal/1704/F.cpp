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

vi dp(500, 0);

int Gett(ll vl)
{
    if (vl <= 290)
        return dp[vl];
    vl -= 290;
    vl %= 34;
    vl += 290;
    return dp[vl];
}

int solve()
{
    cin >> n;

    string s;
    cin >> s;
    a = 0;
    b = 0;

    ll ab = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'R')
            ++a;
        else
            ++b;
    }


    if (a > b)
    {
        cout << "Alice" << endl;
        return 0;
    }
    else if (b > a)
    {
        cout << "Bob" << endl;
        return 0;
    }


    vl lens;
    for (int i = 0; i < n-1; ++i)
    {
        if (s[i] != s[i+1])
        {
            int cr = 2;
            while(true)
            {
                ++i;
                if (i == n-1)
                    break;
                if (s[i] != s[i+1])
                    ++cr;
                else
                    break;
            }
            lens.pb(cr);
        }
    }

    ans = 0;
    for (int i = 0; i < lens.size(); ++i)
    {
        ans ^= Gett(lens[i]);
    }


    if (ans != 0)
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;

    return 0;
}


int main()
{
    FAST;

    for (int i = 2; i < dp.size(); ++i)
    {
        vi cr;

        for (int j = 0; j <= i-2; ++j)
        {
            int vl = dp[j]^dp[i-j-2];
            cr.pb(vl);
        }

        sort(all(cr));
        int cur = 0;
        for (int j = 0; j < cr.size(); ++j)
        {
            //log(cr[j]);
            if (cur < cr[j])
            {
                break;
            }
            cur = cr[j]+1;
        }
        dp[i] = cur;
        /*cout << "dp[" << i << "]:\t ";
        cout << dp[i] << ' ';
        for (int j = 0; j < dp[i]; ++j)
        {
            cout << '|';
        }
        cendl;*/
    }

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}