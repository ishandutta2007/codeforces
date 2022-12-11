#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define F first
#define S second
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
 
 
using namespace std;
const ll INFLL = 1e18;
const int MAXN = 5e5+10;
const ll INF = 1e9;
const ll kek=998244353;
 
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    ll l=1,r=n*m;
    ll ans;
    while (l<=r)
    {
    ll mid=(l+r)/2;
    ll cnt=0;
    for (ll i=1;i<=m;i++)
    {
     cnt+=min(mid/i,n);
    }
    if (cnt>=k)
    {
        ans=mid;
        r=mid-1;
    }
    else
        l=mid+1;
    }
    cout<<ans;
}