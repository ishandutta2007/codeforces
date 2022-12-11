#include <bits/stdc++.h>
using namespace std;
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
#define vb vector <bool>
#define vvb vector <vb>
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define MANX MAXN
#define itn int
#define dbg(x); {cout<<#x<<"="<<x<<", ";}
#define in(x); { for (auto &to : x) cin>>to;}
#define out(x); { for (auto &to : x) cout<<to<<" ";cout<<'\n'; }

const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

void solve()
{
    int n;
    cin>>n;
    vector <int> a(n);
    rep(i,n)
    cin>>a[i];
    sort(all(a));
    int l=0,r=n;
    int ans;
    vector <int> c(n,-1);
    while (l<=r)
    {
        int mid=((l+r)>>1);
        int low=mid,high=mid+1;
        if (low+high>n)
        {
            r=mid-1;
            continue;
        }
        int cur=n-2;
        bool ok=true;
        for (int i=low-1;i>=0;i--)
        {
            ok&=(a[i]<a[cur+1]&&a[i]<a[cur]);
            cur--;
        }
        if (ok)
            ans=mid,l=mid+1;
        else
            r=mid-1;
    }
    cout<<ans<<'\n';
    int low=ans;
    int cur=n-1;
    int where_end=1;
    int now=0;
    for (;low>0;low--)
    {
        c[where_end]=a[now++];
        where_end+=2;
    }
    int begg=where_end;
    where_end--;
    low=ans+1;
    while (low>0)
    {
        c[where_end]=a[cur--];
        where_end-=2;
        low--;
    }
    for (;begg<n;begg++)
        c[begg]=a[cur--];
    out(c);
}

int main() {
   // ios_base::sync_with_stdio(0);
    //cin.tie(0);
    #ifdef Mip182
    freopen("a.in","r",stdin);
    #endif
    int _t;
    _t=1;
//    cin>>_t;
    while (_t--)
        solve();
    //n=1 ?
    //recursion - matrix exponential
    //linear algebra - just a joke
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
    //compression
}