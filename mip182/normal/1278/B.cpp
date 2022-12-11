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

    int t;
    cin>>t;
    while (t--)
    {
    ll a,b;
    cin>>a>>b;
    ll g=abs(a-b);
    if (g==0)
    {
        cout<<0<<'\n';
        continue;
    }
    ll l=0,r=1e9;
    ll ans=0;
    while (l<=r)
    {
    ll mid=(l+r)/2;
    if (mid*(mid+1)/2>=g)
        ans=mid,r=mid-1;
    else
        l=mid+1;
    }
    while ((ans*(ans+1)/2)%2!=g%2)
        ans++;
    cout<<ans<<'\n';
    }





}