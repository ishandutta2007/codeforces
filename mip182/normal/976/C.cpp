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
bool comp (pair <pii,int> a,pair <pii,int> b)
{
    if (a.first.fi==b.fi.fi) return a.fi.se>b.fi.se;
    else
        return a.fi.fi<b.fi.fi;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    int n;
    cin>>n;
    vector <pair <pii,int> >  a(n);
    rep(i,n)
    cin>>a[i].fi.first>>a[i].fi.second,a[i].se=i;
    sort(all(a),comp);
    int mx=-1;
    int ans=-1;
    for (int i=0;i<n;i++)
    {
    if (mx>=a[i].fi.se)
    {
        cout<<a[i].se+1<<" "<<ans+1;
        return 0;
    } else
        mx=a[i].fi.se,ans=a[i].se;
    }
    cout<<-1<<" "<<-1;



}