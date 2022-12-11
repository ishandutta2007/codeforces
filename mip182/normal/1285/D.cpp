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
int ans=(1<<30)+100;
void check(vector <int> &b,int cur,int x)
{
while (cur>=0)
{
    int cnt=0;
    for (int i=0;i<b.size();i++)
    {
        if ((b[i]>>cur)&1)
            cnt++;
    }
    if (cnt==b.size()||cnt==0)
    {
        if (cnt==b.size())
            x^=((ll)(1)<<cur);
        cur--;
    } else
    {
        vector <int> c,d;
        for (int i=0;i<b.size();i++)
        {
            if ((b[i]>>cur)&1)
                c.pb(b[i]);
            else
                d.pb(b[i]);
        }
        check(c,cur-1,x);
        check(d,cur-1,(x^((ll)(1)<<cur)));
        return;
    }
}
if (cur==-1&&b.size()!=0)
{
    int mx=-1000;
    for (int i=0;i<b.size();i++)
    {
    mx=max(mx,b[i]^x);
    }
    ans=min(ans,mx);
}
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
  //  cout<<ans<<'\n';
    int n;
    cin>>n;
    vi a(n);
    rep(i,n)
    cin>>a[i];
    ll x=0;
    check(a,30,0);
    cout<<ans;




}