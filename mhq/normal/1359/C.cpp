#include<bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long int lli;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vop;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<int> vi;
typedef long double ld;
#define double ld
typedef pair<int, int> pii;
#define REP(i,a,b) for( int i=a;i<b;i++)
#define REPR(i,a,b) for(int i=a;i>=b;i--)
#define adb(a) for(auto i:a) cout << i << " "; cout << endl
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define endl "\n"
#define mem(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define PI 3.14159265358979323846

struct LessSecond
{
    template<typename T, typename U>
    bool operator()(const std::pair<T, U> &x, const std::pair<T, U> &y) const
    {
        return x.second < y.second;
    }
};

ll power(ll a, ll b, ll m) { ll ans = 1; a = a % m; while (b) { if (b & 1) ans = (ans * a) % m; b /= 2; a = (a * a) % m; } return ans; }

ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }

ll modInverse(ll a, ll m) { ll g = __gcd(a, m); return power(a, m - 2, m); }


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    fastIO;
    int test = 1;
    cin >> test;
    while (test--)
    {
        ll h, c, t;
        cin >> h >> c >> t;
        if (h == t)
        {
            cout << 1 << endl;
            continue;
        }
        if ((h + c) / 2 == t)
        {
            cout << 2 << endl;
            continue;
        }
        if (h - t >= t - c)
        {
            cout << 2 << endl;
            continue;
        }
        double ans = 1000000000000000009.00;
        ll z = INT_MAX;
        //vector<pair<double, ll>> v;
        ll res = 0;
        ll l = 1, hi = 1000000000000000000, mid;
        while (l <= hi)
        {
            mid = (l + hi) / 2;
            ll an = 1 + (mid - 1) * 2;
            ll x = ceil((double)an / 2);
            ll y = an / 2;
            double cur = (double)((double)(x * h + y * c) / (double)(x + y));
            //cout << an << " " << x << " " << y << " " << cur << " ";
            double dif = double(abs(double(t) - cur));
            //cout << dif << " " << endl;
            //v.PB(make_pair(dif, an));
            if (dif < ans)
            {
                ans = dif;
                z = an;
            }
            else if (dif == ans)
            {
                if (z > an)
                    z = an;
            }
            if (double(t) >= cur) {
                hi = mid - 1;
            }
            else if (double(t) < cur)
            {

                l = mid + 1;
            }
            else
            {
                //ans = min(ans, an);
                break;
            }
            //ans = min(ans, an);
        }
        //sort(all(v));
        cout << z << endl;
        //cout << ans << endl;
    }
    return 0;
}