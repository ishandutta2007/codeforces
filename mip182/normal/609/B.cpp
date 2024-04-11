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
    int n,m;
    cin>>n>>m;
    map<ll,ll> k;
    while (n--)
    {
        int x;
        cin>>x;
        k[x]++;
    }
    vector <ll> a;
    for (auto to:k)
        a.pb(to.second);
    int q=a.size();
    vector <ll> pref(q+1);
    pref[0]=0;
    for (int i=1;i<=q;i++)
        pref[i]=pref[i-1]+a[i-1];
    ll ans=0;
    for (int i=0;i<q-1;i++)
        ans+=a[i]*(pref[q]-pref[i+1]);
    cout<<ans;
}