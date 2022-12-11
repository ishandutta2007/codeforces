#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define vvi vector <vector <int> >
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 5e5+100;
const ll INF = 1e9;
const ll kek=998244353;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
int n,m,cnt=1,mx=-1,xm=INF;
vvi g;
vector <int> used;


void dfs(int s)
{
    used[s]=cnt;
    xm=min(xm,s),mx=max(mx,s);
    for (auto to:g[s])
    {
        if (used[to]==0)
            dfs(to);
    }
}
ll parent[MAXN],ranks[MAXN];
void make_set (int v) {
    parent[v] = v;
    ranks[v] = 0;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (ranks[a] < ranks[b])
            swap (a, b);
        parent[b] = a;
        if (ranks[a] == ranks[b])
            ++ranks[a];
    }
}
int main() {
   ios_base::sync_with_stdio(0); cin.tie(0);
    scanf("%d%d",&n,&m);
    used=vector <int> (n,0);
    g=vvi (n);
    for (int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector <ll> minpos;
    vector <ll> maxpos;

    for (int i=0;i<n;i++)
    {
        if (used[i]==0&&g[i].size()>0)
        {
            dfs(i);
            cnt++;
            minpos.pb(xm);
            maxpos.pb(mx);
            mx=-1,xm=INF;
        }
    }
   // cout<<"haha";
    vector <int> da(n+1,0);
    for (int i=0;i<minpos.size();i++)
    {
            da[minpos[i]]++;
            da[maxpos[i] + 1]--;
    }
    ll ans=0;
    int cnt=0;
   // cout<<"haha";
    for (int i=0;i<n;i++)
    {
        cnt+=da[i];
      //  cout<<cnt<<" "<<i<<'\n';
        if (used[i]==0&&cnt)
            ans++;
    }
  //  for (int i=0;i<n;i++)
   //     cout<<used[i]<<" ";

    int x=0,y=0;
    vector <int> u;
    while (x<n)
    {
        while (y<n&&used[x]==used[y])
            y++;
        if (used[x]!=0)
        u.pb(used[x]);
        x=y;
    }

    map <ll,ll> t;
    //for (int i=0;i<u.size();i++)
   //    cout<<u[i]<<" ";
    int i=0;
    map <ll,ll> p;
    for (int f=0;f<u.size();f++) {
        if (p[u[f]]==0)
        make_set(u[f]),p[u[f]]++;
    }
    while (i<u.size())
    {
        if (t[find_set(u[i])]==0)
            t[find_set(u[i])]++,i++;
        else
        {
            int j=i-1;
            vector <int> index;
            while (find_set(u[j])!=find_set(u[i]))
                index.pb(j),j--;
            for (int k=0;k<index.size();k++) {
                if (find_set(u[index[k]]) != find_set(u[i])) {
                    t[find_set(u[index[k]])]++;
                    union_sets(u[index[k]], u[i]), ans++;
                    t[find_set(u[index[k]])]++;
                }
            }
            t[find_set(u[i])]++;
          //  cout<<i<<'\n';
            i++;

        }
    }

    printf("%d",ans);
}