#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define vvi vector <vector <int> >
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define int long long


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 5e5+100;
const ll INF = 1e9;
const ll kek=998244353;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,m;
    cin>>n>>m;
    vector <ll> a(n);
    rep(i,n)
    cin>>a[i];
    sort(a.begin(),a.end());
    vector <ll> pref[m];
    vector <ll> div[m];
    for (int i=0;i<n;i++)
        div[i%m].pb(a[i]);
    for (int i=0;i<m;i++)
    {   int r=0;
        if (div[i].size()) {
            pref[i].pb(div[i][0]);
            r=div[i][0];
        }

        for (int j=1;j<(int)(div[i].size());j++) {
            pref[i].pb(r+ div[i][j]);
            r=r+ div[i][j];
        }
    }
    ll sum=0;
    for (int i=0;i<n;i++)
    {   sum+=a[i];
        int j=i%m;
        int q=i/m;
        if (q)
        sum+=pref[j][q-1];
        cout<<sum<<" ";
    }


}