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
#define vvll vector <vll>
#define vsi vector <si>
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
  //  freopen("a.in","r",stdin);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector <int> a(n);
        rep(i,n)
            cin>>a[i];
        int ans=0;
        vector <int> b[201];
        vector <vector <int> > pref(n+1);
        for (int i=0;i<=n;i++)
            pref[i].resize(201);
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=200;j++)
                pref[i][j]+=pref[i-1][j];
            pref[i][a[i-1]]++;
        }
      //  cout<<"haha"
        for (int i=0;i<n;i++)
            b[a[i]].pb(i);
        for (int i=1;i<=200;i++)
        {
            ans=max(ans,pref[n][i]);
        }
        for (int i=1;i<=200;i++)
        {
            for (int k=0;k<b[i].size()/2;k++)
            {
                int x=b[i][k],y=b[i][(int)(b[i].size())-1-k];
                int mx=0;
                for (int j=1;j<=200;j++)
                    mx=max(pref[y][j]-pref[x+1][j],mx);
                ans=max(ans,mx+2*(k+1));
            }
        }
        cout<<ans<<'\n';
    } }