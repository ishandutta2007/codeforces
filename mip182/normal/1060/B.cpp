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
    ll n;
    cin>>n;
    ll t=n;
    vector <int> x;
    while (t)
    {
        x.pb(t%10);
        t/=10;
    }
    ll q=0;
    ll f=9;
    ll cnt=0;
    while (q+f<=n)
    {
    cnt++;
    q+=f;
    f*=10;
    }
    f=1;
    for (int i=0;i<cnt;i++)
        f*=10;
    while (q+f<=n)
        q+=f;
    ll y=n-q;
    ll ans=0;
    while (y)
    {
        ans+=y%10;
        y/=10;
    }
    while (q)
    {
        ans+=q%10;
        q/=10;
    }
    cout<<ans;


}