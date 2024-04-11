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
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define rep(i, n) for (int i = 0; i < (n); i++)
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
    int n,m;
    cin>>n>>m;
    vector <ll> a(n);
    rep(i,n)
    cin>>a[i];
    vector <ll> b(m);
    rep(i,m)
    cin>>b[i];
    ll x;
    cin>>x;
    vector <ll> prefa(n+1,0),prefb(m+1,0);
    rep(i,n)
    prefa[i+1]=prefa[i]+a[i];
    rep(i,m)
    prefb[i+1]=prefb[i]+b[i];
    ll ans=0;
    vector <ll> minprefa(n+1),minprefb(m+1);
    for (int i=1;i<=n;i++){
            ll mx=INF;
            for (int j=i;j<=n;j++)
                mx=min(mx,prefa[j]-prefa[j-i]);
    minprefa[i]=mx;
           }
    for (int i=1;i<=m;i++){
            ll mx=INF;
            for (int j=i;j<=m;j++)
                mx=min(mx,prefb[j]-prefb[j-i]);
    minprefb[i]=mx;
           }
    for (ll i=1;i<=n;i++)
    {
        for (ll j=1;j<=m;j++)
        {
            if (minprefa[i]!=INF&&minprefb[j]!=INF&&minprefa[i]*minprefb[j]<=x)
                ans=max(ans,i*j);
        }
    }
    cout<<ans;



}