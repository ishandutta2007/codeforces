//#define _GLIBCXX_DEBUG
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
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define MANX MAXN


const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
vvi g;
vector <pii> a;
vector <int> d;
vector <int> where;
void dfs(int s,int p,int ok)
{
    a.pb({ok,s});
    d[s]=ok;
    for (auto to:g[s])
    {
        if (to==p)
            continue;
        dfs(to,s,ok+1);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    #ifdef LOCAL
//    freopen("a.in","r",stdin);
//    #endif
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        g=vvi(n);
        d=vi(n);
        where=vi(n,-1);
        for (int i=0;i<n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            u--,v--;
            g[u].pb(v);
            g[v].pb(u);
        }
        a.clear();
        int cnt=0;
        dfs(0,-1,0);
        sort(all(a));
        for (int i=0;i<n;i++)
            where[a[i].se]=i;
        cout<<"? "<<n<<" ";
        cnt++;
        for (int i=0;i<n;i++)
            cout<<i+1<<" ";
        cout<<endl;
        int x,dd;
        cin>>x>>dd;
        if (x==-1)
        {
            while(1);
        }
        x--;
  //      int vert=where[x];
        if (a.size()!=n)
        {
            while (1);
        }
        assert(where[x]!=-1);
        int l=max(where[x]+1,0),r=n-1;
        while (l<=r)
        {
            int mid=((l+r)>>1);
            cout<<"? "<<n-1-mid+1<<" ";
            for (int i=mid;i<n;i++)
                cout<<a[i].se+1<<" ";
            cout<<endl;
            int xxx,ddd;
            cin>>xxx>>ddd;
            if (xxx==-1)
            {
                while (1);
            }
            xxx--;
            if (ddd==dd)
            {
                l=mid+1;
                x=xxx;
            }
            else
                r=mid-1;
        }
        int dist=dd;
        d=vi(n);
        a.clear();
        dfs(x,-1,0);
        vector <int> cand;
        for (int i=0;i<n;i++)
        {
            if (d[i]==dist)
                cand.pb(i);
        }
        assert(cand.size()>0);
        int ans,okok;
        if (cand.size()>1) {
            cout << "? " << cand.size() << " ";
            for (auto to:cand)
                cout << to + 1 << " ";
            cout << endl;
            cin >> ans >> okok;
            if (ans==-1)
            {
                while (1);
            }
          //  assert(okok==dist);
        }
        else
            ans=cand[0]+1;
        cout<<"! "<<x+1<<" "<<ans<<endl;
        string s;
        cin>>s;
        if (s=="Incorrect")
        {
            while (1);
        }
      //  assert(s=="Correct");

    }


    //n=1 ?
    //recursion - matrix exponential
    //linear algebra - just a joke
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
    //compression
}