#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
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
    ll k1,k2,k3;
    cin>>k1>>k2>>k3;
    vector <int> dp;
    vi a(k1),b(k2),c(k3);
    rep(i,k1)
    cin>>a[i];
    rep(i,k2)
    cin>>b[i];
    rep(i,k3)
    cin>>c[i];
    sort(a.begin(),a.end());
    sort(all(b));
    sort(all(c));
    for (int i=0;i<k1;i++)
    {
        int x;
        x=a[i];
        auto k=lower_bound(dp.begin(),dp.end(),x);
        if (k==dp.end())
            dp.pb(x);
        else
            *k=x;
    }
    for (int i=0;i<k2;i++)
    {
        int x;
        x=b[i];
        auto k=lower_bound(dp.begin(),dp.end(),x);
        if (k==dp.end())
            dp.pb(x);
        else
            *k=x;
    }
    for (int i=0;i<k3;i++)
    {
        int x;
        x=c[i];
        auto k=lower_bound(dp.begin(),dp.end(),x);
        if (k==dp.end())
            dp.pb(x);
        else
            *k=x;
    }
    cout<<k1+k2+k3-(int)dp.size();
}