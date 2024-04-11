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
    cin >> n;
    string s, s_;
    cin >> s >> s_;

    if (s == s_)
    {
        cout << 0 << endl;
        return 0;
    }

    bool is0 = true;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] != '0') is0 = false;
    }
    if (is0)
    {
        cout << -1<<endl;
        return 0;
    }

    is0 = true;
    for (int i = 0; i < n; ++i)
    {
        if (s_[i] != '0') is0 = false;
    }
    if (is0)
    {
        cout << -1<<endl;
        return 0;
    }



    ll inf = 10000000;

    ans = inf;


    ll _1 = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '1')
            _1++;
    }

    ll _1_ = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s_[i] == '1')
            _1_++;
    }

    if (_1 != _1_ && n - (_1-1) != _1_)
    {
        cout << -1 << endl;
        return 0;
    }

    ll _00 = 0;
    ll _01 = 0;
    ll _10 = 0;
    ll _11 = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0' && s_[i] == '0')
            _00++;
        if (s[i] == '0' && s_[i] == '1')
            _01++;
        if (s[i] == '1' && s_[i] == '0')
            _10++;
        if (s[i] == '1' && s_[i] == '1')
            _11++;
    }

    if (_10 == _01)
    {
        ans = min(ans, _01+_10);
    }

    if (_11 == _00+1)
    {

        ans = min(ans, _00+_11);
    }



    if (ans != inf)
    cout << ans << endl;
    else
        cout << -1<< endl;

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