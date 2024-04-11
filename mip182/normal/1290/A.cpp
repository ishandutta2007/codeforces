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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
    freopen("a.in","r",stdin);
    #endif
    int t;
    cin>>t;
    while (t--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        vector <ll> a(n);
        ll mx=-1;
        rep(i,n)
        cin>>a[i],mx=max(mx,a[i]);
        ll l=1,r=mx;
        ll ans=1;
        while (l<=r)
        {
           ll mid=(l+r)/2;
           int f=min(k,m-1);
           int h=m-1-f;
           bool ok=false;
           for (int i=0;i<=f;i++)
           {
               bool ko=true;
               for (int j=0;j<=h;j++)
               {
                 //  cout<<i<<" "<<j<<" "<<f<<" "<<h<<" "<<a[i+j]<<" "<<a[n-1-(f-i)-(h-j)]<<'\n';
                   if ((a[i+j]<mid)&&(a[n-1-(f-i)-(h-j)]<mid))
                   {
                       ko=false;
                       break;
                   }
               }
               if (ko)
               {
                 ok=true;
                 break;
               }
           }
           if (ok)
               ans=mid,l=mid+1;
           else
               r=mid-1;
        }
        cout<<ans<<'\n';
    }




}