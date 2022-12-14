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

template<typename T1, typename T2> ostream& operator<<(ostream& out, const pair<T1, T2>& x) {return out << x.first << ' ' << x.second;}
template<typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& x) {return in >> x.first >> x.second;}
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};


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

    vi dt(n);
    cin >> dt;

    ans = 0;

    vl g1;
    vl g2;
    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        ans += x;

        if (dt[i] == 0)
            g1.pb(x);
        else
            g2.pb(x);
    }
//
    //log(ans);

    sort(all(g1));
    sort(all(g2));
    //log(g1);
    //log(g2);

    if (g1.size() == g2.size())
    {
        ll minx = min(g1[0], g2[0]);
        ans *= 2;
        ans -= minx;
        cout << ans << endl;
        return 0;
    }

    for (int i = 0; i < min(g1.size(), g2.size()); ++i)
    {
        ans += g1[g1.size()-1-i];
        ans += g2[g2.size()-1-i];
    }




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