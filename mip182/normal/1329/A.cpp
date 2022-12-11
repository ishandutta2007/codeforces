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
    int n,m;
    cin>>n>>m;
    vector <ll> p(m);
    ll sum=0;
    rep(i,m)
        cin>>p[i],sum+=p[i];
    ll cur=0;
    vector <int> ans;
    int i=0;
    while (i<m&&cur<n)
    {
        if (n-p[i]+1>cur)
            ans.pb(cur),i++,cur++;
        else
            break;
    }
    if (ans.size()==m&&sum>=n)
    {
        vector <int> anss(m);
        rep(i,m)
            anss[i]=i;
        int left=m+p[m-1]-1,right=0;
        int now=m-1;
        while (left+right<n)
        {
         //   cout<<left<<" "<<right<<'\n';
          //  cout<<now+p[now-1]-1+right+p[now]<<'\n';
            if (now+p[now-1]-1+right+p[now]<=n)
                anss[now]=n-right-p[now],right+=p[now],left=now+p[now-1]-1,now--;
            else
            {
                anss[now]=n-right-p[now];
                break;
            }
        }
        for (int i=0;i<m;i++)
            cout<<anss[i]+1<<" ";
    }
    else
        cout<<-1;





}