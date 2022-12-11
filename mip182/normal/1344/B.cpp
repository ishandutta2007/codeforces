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


const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
int par[MAXN],ranks[MAXN];
vector <int> x={0,0,1,-1};
vector <int> y={1,-1,0,0};
void make_set(int s)
{
    ranks[s]=0;
    par[s]=s;
}
int find_set(int s)
{
    if (s==par[s])
        return s;
    return find_set(par[s]);
}
void union_sets(int u,int v)
{
    u=find_set(u);
    v=find_set(v);
    if (u!=v)
    {
        if (ranks[u]<ranks[v])
            swap(u,v);
        par[v]=u;
        if (ranks[u]==ranks[v])
            ranks[u]++;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    int n,m;
    cin>>n>>m;
    vector <string> s(n);
    rep(i,n)
    cin>>s[i];
    int chett=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (s[i][j]=='.')
                chett++;
        }
    }
    if (chett==n*m)
    {
        cout<<0;
        return 0;
    }
    for (int i=0;i<n;i++)
    {
        int cur=0;
        while (cur<m&&s[i][cur]=='.')
            cur++;
        while (cur<m&&s[i][cur]=='#')
            cur++;
        while (cur<m&&s[i][cur]=='.')
            cur++;
        if (cur!=m)
        {
            cout<<-1;
            return 0;
        }
    }
    for (int j=0;j<m;j++)
    {
        int cur=0;
        while (cur<n&&s[cur][j]=='.')
            cur++;
        while (cur<n&&s[cur][j]=='#')
            cur++;
        while (cur<n&&s[cur][j]=='.')
            cur++;
        if (cur!=n)
        {
            cout<<-1;
            return 0;
        }
    }
    vector <bool> stroki(n),stolb(m);
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (s[i][j]=='#')
                stroki[i]=true;
        }
    }
    for (int j=0;j<m;j++)
    {
        for (int i=0;i<n;i++)
        {
            if (s[i][j]=='#')
                stolb[j]=true;
        }
    }
    int strokcnt=0,stolbcnt=0;
    for (int i=0;i<n;i++)
    {
        if (stroki[i])
           strokcnt++;
    }
    for (int i=0;i<m;i++)
    {
        if (stolb[i])
            stolbcnt++;
    }
    for (int i=0;i<n;i++)
    {
        if (!stroki[i])
        {
            if (stolbcnt==m)
            {
                cout<<-1;
                return 0;
            }
        }
    }
    for (int j=0;j<m;j++)
    {
        if (!stolb[j])
        {
            if (strokcnt==n)
            {
                cout<<-1;
                return 0;
            }
        }
    }
    int ans=0;
    for (int i=0;i<n*m;i++) {
        if (s[i/m][i%m]=='#')
        make_set(i),ans++;
    }
    for (int i=0;i<n*m;i++)
    {
        int xx=i/m,yy=i%m;
        if (s[xx][yy]=='.')
            continue;
        for (int j=0;j<4;j++)
        {
            if (xx+x[j]<n&&xx+x[j]>=0&&yy+y[j]<m&&yy+y[j]>=0&&s[xx+x[j]][yy+y[j]]=='#')
            {
                if (find_set(i)!=find_set((xx+x[j])*m+yy+y[j]))
                    ans--;
                union_sets(i,(xx+x[j])*m+yy+y[j]);
            }
        }
    }
    cout<<ans;



}