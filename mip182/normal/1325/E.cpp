//#define _GLIBCXX_DEBUG
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
int ans=INF;
vvi g;
int par[MAXN];
vector <int> used;

void dfs(int s,int p)
{
    used[s]=1;
    par[s]=p;
//    cout<<p<<" "<<s<<'\n';
    for (auto to:g[s])
    {
        if (to==p)
            continue;
        if (used[to]==1)
        {
            int cnt=0;
            int x=p;
            //cout<<to<<" "<<s<<'\n';
            while (x!=to) {
                cnt++, x = par[x];
            }
            cnt++;
            ans=min(ans,cnt+1);
          //      return ;
        }
        else {
            if (used[to]==0)
            dfs(to, s);
        }
    }
    used[s]=2;
}
int main() {
//    ios_base::sync_with_stdio(0);
   // cin.tie(0);
    #ifdef LOCAL
    freopen("a.in","r",stdin);
    #endif
    clock_t times=clock();
    int n;
    cin>>n;
    vector <int> a(n);
    rep(i,n)
    cin>>a[i];
    vector <pair <int,int> > b(n,{-1,-1});
    rep(i,n)
    {
        b[i]={1,1};
        int cnt=-1,cnt1=-1;
        for (int j=2;j*j<=a[i];j++)
        {
         //   cout<<cnt<<" "<<cnt1<<'\n';
            if (a[i]%j==0)
            {
             //   cout<<j<<'\n';
                if (cnt==-1)
                {
                    cnt=0;
                    while (a[i]%j==0)
                        cnt++,a[i]/=j;
                    if (cnt%2==1)
                        b[i].fi=j;
                  //  cout<<b[i].fi<<'\n';
                  //  cout<<cnt<<" "<<cnt1<<'\n';
                }
                else
                {
                    cnt1=0;
                    while (a[i]%j==0)
                        cnt1++,a[i]/=j;
                    if (cnt1%2==1)
                        b[i].se=j;
                  //  cout<<b[i].se<<'\n';
                }
            }
        }
        if (a[i]>1)
            b[i].se=a[i];
    }
    for (int i=0;i<n;i++)
    {
        if (b[i].fi>b[i].se)
            swap(b[i].fi,b[i].se);
    }
    for (int i=0;i<n;i++)
    {
        if (b[i].fi==1&&b[i].se==1)
        {
            cout<<1;
            return 0;
        }
    }
  //  rep(i,n)
 //   {
  //      cout<<b[i].fi<<" "<<b[i].se<<'\n';
  //  }
    map <pair <int,int>,int> m;
    for (int i=0;i<n;i++)
    {
        if (m[b[i]]!=0)
        {
            cout<<2;
            return 0;
        }
        else
            m[b[i]]=1;
    }
    set <int> c;
    map <int,int> mm;
    for (int i=0;i<n;i++)
    {
        c.insert(b[i].fi);
        c.insert(b[i].se);
    }
    vector <int> d(c.size());
    int cur=0;
    for (auto to:c) {
        mm[to]=cur;
        d[cur++] = to;
    }
    //cout<<mm[2]<<" "<<mm[3]<<" "<<mm[5]<<'\n';
    g=vvi(d.size());
    for (int i=0;i<n;i++)
    {
        g[mm[b[i].fi]].pb(mm[b[i].se]);
        g[mm[b[i].se]].pb(mm[b[i].fi]);
    }
//    for (int i=0;i<c.size();i++)
//    {
//        cout<<i<<'\n';
//        for (auto to:g[i])
//            cout<<to<<" ";
//        cout<<'\n';
//    }
   // cout<<"aha";
   vector <int> haha(c.size());
    rep(i,c.size())
    haha[i]=i;
    mt19937 r(1337);
    while (clock()-times<=2500) {
        shuffle(all(haha),r);
        used=vi(c.size(),0);
        for (int i = 0; i < c.size(); i++) {
            if (used[haha[i]] == 0) {
                dfs(haha[i], haha[i]);
            }
        }
    }
    if (ans==INF)
    {
        cout<<-1;
        return 0;
    } else
        cout<<ans;



}