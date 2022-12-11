#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 5e5+100;
const ll INF = 1e9;
const ll kek=998244353;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
    ll a,b;
    cin>>a>>b;
    if (a<b)
        swap(a,b);
    ll ans=0;
    ll d=a-b;
    ans+=d/5;
    d-=(d/5)*5;
    if (d==4)
        ans+=2;
    if (d==1)
        ans+=1;
    if (d==2)
        ans+=1;
    if (d==3)
        ans+=2;
    cout<<ans<<'\n';
    }
}