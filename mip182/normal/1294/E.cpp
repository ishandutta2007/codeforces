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
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
            cin>>a[i][j];
    }
    ll ans=0;
    for (int i=0;i<m;i++)
    {
        map <int,ll> mm;
        ll mx=INF;
        for (int j=0;j<n;j++)
        {
            int q=a[j][i]%m;
            if (q!=((i+1)%m))
                continue;
            int f=(a[j][i]-1)/m;
            if (f>n-1)
                continue;
            mm[(j-f+n)%n]++;
        }
     //   int f=INF;
        for (auto to:mm) {
        //    cout<<to.first<<" "<<to.second<<'\n';
            mx = min(mx, to.fi +n-to.se);
        }
        if (mm.size()==0)
            mx=n;
        mx=min(mx,(ll)n);
    //    cout<<mx<<'\n';
     //   cout<<mx<<'\n';
     //   cout<<1+n-mx<<'\n';
        ans+=mx;
    }
    cout<<ans;





}