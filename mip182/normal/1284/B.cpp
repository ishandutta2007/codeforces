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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
    freopen("a.in","r",stdin);
    #endif
    ll n;
    cin>>n;
    vector <vector <int> > s(n);
    vector <int> good(n,0);
    vector <int> mini(1e6+1,0),maxi(1e6+1,0);
    vector <int> minu(n);
    ll cnt=0,ans=0;
    rep(i,n)
    {
        int l;
        cin>>l;
        vector <int> a(l);
        bool ok=false;
        int mx=-1,xm=INF;
        rep(j,l){
        cin>>a[j];
        mx=max(mx,a[j]);
        xm=min(xm,a[j]);
        }
        for (int j=0;j<l-1;j++)
        {
          if (a[j]<a[j+1])
              ok=true;
        }
        if (ok) {
            good[i] = 1, cnt++;
            minu[i]=-1;
        }
        else {
            mini[xm]++;
            maxi[mx]++;
            minu[i] = xm;
        }
        s[i]=a;
    }
    vector <int> pref(1e6+1);
    pref[0]=maxi[0];
    for (int i=1;i<1e6+1;i++)
        pref[i]=pref[i-1]+maxi[i];
    for (int i=0;i<n;i++)
    {
        if (minu[i]!=-1)
        {
            ans+=pref[1e6]-pref[minu[i]];
        }
    }
    ans+=(cnt*(n-cnt))*2+cnt*cnt;
    cout<<ans;






}