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
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define MANX MAXN
#define itn int
#define in(x); { for (auto &to : x) cin>>to;}
#define out(x); { for (auto &to : x) cout<<to<<" ";cout<<'\n'; }

const ll INFLL = 1e18;
const int MAXN = 1e5+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
vector <vpii> g;
vll cnt;
int dp[MAXN];
void dfs(int s,int p)
{
    dp[s]=0;
    for (auto to:g[s])
    {
        if (to.fi==p)
            continue;
        dfs(to.fi,s);
        cnt[to.se]=dp[to.fi];
        dp[s]+=dp[to.fi];
    }
    if (g[s].size()==1)
        dp[s]++;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef Mip182
    freopen("a.in","r",stdin);
    #endif
    int t;
    cin>>t;
    while (t--)
    {
        ll n,S;
        cin>>n>>S;
        vector <ll> w(n+1);
        g=vector <vpii>(n);
        cnt=vll(n+1);
        vector <ll> c(n+1);
        rep(i,n-1)
        {
            int v,u,ww,cc;
            cin>>v>>u>>ww>>cc;
            v--,u--;
            g[u].pb({v,i});
            g[v].pb({u,i});
            w[i]=ww;
            c[i]=cc;
         // c[i]=1;
        }
        vll www=w;
        dfs(0,0);
        set <pll> one,two;
        ll sum=0;
        for (int i=0;i<n-1;i++)
        {
            if (c[i]==1)
                one.insert({cnt[i]*(w[i]-w[i]/2),i});
            else
                two.insert({cnt[i]*(w[i]-w[i]/2),i});
            sum+=cnt[i]*w[i];
        }
        two.insert({0,n+1});
        one.insert({0,n});
        ll ans=0;
        while (sum>S)
        {
      //      cout<<sum<<" "<<S<<'\n';
            auto to=one.end();
            to=prev(to);
            ll f=(*to).fi;
//            cout<<f<<'\n';
//            if (sum-f<=S) {
//                ans++;
//                break;
//            }
            ans+=2;
            auto too=two.end();
            too=prev(too);
            ll ff=(*too).fi;
            ll x=(*to).se;
            ll was=w[x];
            w[x]=w[x]/2;
            one.erase(to);
            one.insert({cnt[x]*(w[x]-w[x]/2),x});
            auto tooo=one.end();
            tooo=prev(tooo);
            ll fff=(*tooo).fi;
            if (ff>=fff+f)
            {
                sum-=ff;
                ll y=(*too).se;
                w[y]=w[y]/2;
                two.erase(too);
                two.insert({cnt[y]*(w[y]-w[y]/2),y});
                one.erase({cnt[x]*(w[x]-w[x]/2),x});
                w[x]=was;
                one.insert({cnt[x]*(w[x]-w[x]/2),x});
            }
            else
            {
                sum-=fff+f;
                ll y=(*tooo).se;
                w[y]=w[y]/2;
                one.erase(tooo);
                one.insert({cnt[y]*(w[y]-w[y]/2),y});
            }
        }
        ll anss=ans;
        ans=0;
        one=set<pll>();
        two=set<pll>();
        two.insert({0,n+1});
        one.insert({0,n});
        w=www;
        sum=0;
        for (int i=0;i<n-1;i++)
        {
            if (c[i]==1)
                one.insert({cnt[i]*(w[i]-w[i]/2),i});
            else
                two.insert({cnt[i]*(w[i]-w[i]/2),i});
            sum+=cnt[i]*w[i];
        }
        auto ha=one.end();
        ha=prev(ha);
        ll go=(*ha).fi,z=(*ha).se;
        ans++;
        sum-=go;
        one.erase(ha);
        w[z]=w[z]/2;
        one.insert({cnt[z]*(w[z]-w[z]/2),z});
        while (sum>S)
        {
         //   cout<<sum<<" "<<S<<'\n';
            auto to=one.end();
            to=prev(to);
            ll f=(*to).fi;
//            cout<<f<<'\n';
//            if (sum-f<=S) {
//                ans++;
//                break;
//            }
            ans+=2;
            auto too=two.end();
            too=prev(too);
            ll ff=(*too).fi;
            ll x=(*to).se;
            ll was=w[x];
            w[x]=w[x]/2;
            one.erase(to);
            one.insert({cnt[x]*(w[x]-w[x]/2),x});
            auto tooo=one.end();
            tooo=prev(tooo);
            ll fff=(*tooo).fi;
            if (ff>=fff+f)
            {
                sum-=ff;
                ll y=(*too).se;
                w[y]=w[y]/2;
                two.erase(too);
                two.insert({cnt[y]*(w[y]-w[y]/2),y});
                one.erase({cnt[x]*(w[x]-w[x]/2),x});
                w[x]=was;
                one.insert({cnt[x]*(w[x]-w[x]/2),x});
            }
            else
            {
                sum-=fff+f;
                ll y=(*tooo).se;
                w[y]=w[y]/2;
                one.erase(tooo);
                one.insert({cnt[y]*(w[y]-w[y]/2),y});
            }
        }
        cout<<min(anss,ans)<<'\n';
    }


    //n=1 ?
    //recursion - matrix exponential
    //linear algebra - just a joke
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
    //compression
}