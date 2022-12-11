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
vector <set<int> >  g;
int cnt=0;
vector <int> used;
int x;
void dfs(int s,int par)
{
    if (s==x)
        return;
    used[s]=1;
    cnt--;
    for (auto to:g[s])
    {
        if (to==par)
            continue;
        if (used[to]==0)
        {
            dfs(to,-1);
        }
    }
}
int main() {
    int n;
    cin>>n;
    g=vector <set<int>  >(n);
    used=vi(n,0);
    cnt=n;
    for (int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].insert(v);
        g[v].insert(u);
    }
    while (cnt>2)
    {
        for (int i=0;i<n;i++)
        {
            if (used[i]==0)
            {
                vector <int> good;
                int chet=0;
                for (auto to:g[i])
                {
                    if (used[to]==0)
                        chet++,good.pb(to);
                }
                if (chet>=2)
                {
                   cout<<"? "<<good[0]+1<<" "<<good[1]+1<<endl;
                   cin>>x;
                   x--;
                   dfs(good[0],x);
                   dfs(good[1],x);

                }


            }
        }
    }
    if (cnt==1)
    {
        int ans=0;
        for (int i=0;i<n;i++)
        {
            if (used[i]==0)
                ans=i;
        }
        cout<<"! "<<ans+1<<endl;
    }
    else
    {
        vector <int> good;
        for (int i=0;i<n;i++)
        {
            if (used[i]==0)
                good.pb(i);
        }
        cout<<"? "<<good[0]+1<<" "<<good[1]+1<<endl;
        int y;
        cin>>y;
        cout<<"! "<<y<<endl;
    }



}