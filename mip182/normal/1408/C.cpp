#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vd vector <double>
#define vll vector <ll>
#define fi first
#define se second
#define si set <int>
#define sll set <ll>
#define spii set <pii>
#define vs vector <string>
#define vpii vector <pair <int, int> >
#define vpll vector <pair <long long, long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define vb vector <bool>
#define vvb vector <vb>
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MANX MAXN
#define itn int
#define dbg(x); {cout<<#x<<"="<<x<<", ";}
#define in(x); { for (auto &to : x) cin>>to;}
#define out(x); { for (auto &to : x) cout<<to<<" ";cout<<'\n'; }

const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1 = 1e9+7;
const ll mod2 = 2e9+11;

void solve()
{
    ll n,L;
    cin>>n>>L;
    vector <ll> a(n);
    in(a);
    double one=0,zero=L;
    long double t=0;
    int l=0,r=n-1;
    ll x=1,y=1;
    while (one<=zero)
    {
        if (l<=r) {
            double t1 = (a[l] - one) / x, t2 = (zero - a[r]) / y;
            double pos1 = min(t1, t2) * x + one, pos2 = -min(t2, t1) * y + zero;
            if (pos1 >= pos2) {
                t += (zero - one) / (x + y);
                break;
            }
            t+=min(t1,t2);
            one = pos1;
            zero = pos2;
            if (one == a[l])
                x++,l++;
            if (zero==a[r])
                y++,r--;

        }
        else
        {
            t += (zero - one) / (x + y);
            break;
        }

    }
    cout<<setprecision(30)<<t<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef Mip182
    freopen("a.in", "r", stdin);
    #endif
    int _t;
    _t=1;
    cin>>_t;
    while (_t--)
        solve();
    //n=1 ?
    //recursion - matrix exponential
    //linear algebra - just a joke
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
    //compression
}