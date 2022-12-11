#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define F first
#define S second
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5+100;
const ll INF = 1e9;
const ll kek=998244353;
const ll mod1=1000000007;
int a[50][50];
int ranks[MAXN];
int parent[MAXN];
vector <int> p={1,-1,0,0};
vector <int> q={0,0,-1,1};
void make_set (int s)
{
    parent[s]=s;
    ranks[s]=0;
}
int find_set(int s)
{
    if (parent[s]==s)
        return s;
    return parent[s]=find_set(parent[s]);
}
void union_sets(int u,int b)
{
    u=find_set(u);
    b=find_set(b);
    if (u!=b)
    {
        if (ranks[u] < ranks[b])
            swap (u, b);
        parent[b] = u;
        if (ranks[u] == ranks[b])
            ++ranks[u];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;
    r1--,c1--,r2--,c2--;
    for (int i=0;i<n;i++)
    {   string s;
        cin>>s;
        for (int j=0;j<n;j++)
            a[i][j]=s[j]-'0';
    }

    for (int i=0;i<n*n;i++) {
        make_set(i);
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
           for (int k=0;k<4;k++)
           {
               if ((i+p[k])<n&&(i+p[k])>=0&&(j+q[k])>=0&&(j+q[k])<n)
               {
                   if (a[i][j]==0&&a[i+p[k]][j+q[k]]==0)
                       union_sets(i+j*n,i+p[k]+n*(j+q[k]));
               }
           }
        }
    }
    int l=find_set(r1+n*c1);
    int r=find_set(r2+n*c2);
    vector <int> g;
    vector <int> d;
    for (int i=0;i<n*n;i++)
    {
        if ((find_set(i))==l)
            g.pb(i);
        if ((find_set(i))==r)
            d.pb(i);
    }
    int ans=INF;
    for (int i=0;i<g.size();i++)
    {
        for (int j=0;j<d.size();j++)
        {
            ans=min(ans,((g[i]%n) -(d[j]%n))*((g[i]%n) -(d[j]%n))+((g[i]/n)-(d[j]/n))*((g[i]/n)-(d[j]/n)));
            //cout<<((g[i]%n) +(d[j]%n))*((g[i]%n) +(d[j]%n))+((g[i]/n)+(d[j]/n))*((g[i]/n)+(d[j]/n))<<'\n';
        }
    }
    cout<<ans;
}