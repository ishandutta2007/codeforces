#include <bits/stdc++.h>
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
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
ll dist(ll x,ll y,ll x1,ll y1)
{
    return (x-x1)*(x-x1)+(y-y1)*(y-y1);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    int n;
    cin>>n;
    vector <pair <ll,ll> > x(n);
    rep(i,n)
    cin>>x[i].fi>>x[i].se;
    if (n&1)
    {
        cout<<"NO";
        return 0;
    }
    for (int i=0;i<n;i++)
    {
        pair <ll,ll> xx=x[i],y=x[(i+1)%n];
        pair <ll,ll> x1=x[(i+n/2)%n],y1=x[(i+n/2+1)%n];
        if (dist(xx.fi,xx.se,y.fi,y.se)!=dist(x1.fi,x1.se,y1.fi,y1.se))
        {
            cout<<"NO";
            return 0;
        }
        ll xxx=xx.fi-y.fi,yyy=xx.se-y.se;
        if (xxx<0)
            xxx*=-1,yyy*=-1;
        ll t=__gcd(xxx,yyy);
        xxx/=t,yyy/=t;
        if (xxx<0)
            xxx*=-1,yyy*=-1;
        if (xxx==0)
            yyy=1;
        if (yyy==0)
            xxx=1;
        ll xxxx=x1.fi-y1.fi,yyyy=x1.se-y1.se;
        if (xxxx<0)
            xxxx*=-1,yyyy*=-1;
        ll tt=__gcd(xxxx,yyyy);
        xxxx/=tt,yyyy/=tt;
        if (xxxx<0)
            xxxx*=-1,yyyy*=-1;
        if (xxxx==0)
            yyyy=1;
        if (yyyy==0)
            xxxx=1;
        if (xxxx!=xxx||yyy!=yyyy)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";




}