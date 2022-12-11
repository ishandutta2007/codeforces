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
const int MAXN = 5e5+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    // a  d    // b c d
    ll ans=0;
    if (e>=f)
    {
      ans+=min(a,d)*e;
      ll t=min(a,d);
      a-=t,d-=t;
      ans+=min(b,min(d,c))*f;
    }
    else
    {
        ans+=min(b,min(d,c))*f;
        ll t=min(b,min(d,c));
        b-=t,d-=t,c-=t;
        ans+=min(a,d)*e;
    }
    cout<<ans<<'\n';



}