#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 1005

string s[MAXN];
vector<int> g[MAXN*MAXN];
int c[MAXN][MAXN],level[MAXN*MAXN],sz,cont;
bool mk[MAXN*MAXN],mk1[MAXN][MAXN];
int n,m,t;

void dfs(int i,int j)
{
    mk1[i][j]=1;
    c[i][j]=cont;
    sz++;
    if(i && !mk1[i-1][j] && s[i-1][j]==s[i][j])
        dfs(i-1,j);
    if(j && !mk1[i][j-1] && s[i][j-1]==s[i][j])
        dfs(i,j-1);
    if(i<n-1 && !mk1[i+1][j] && s[i+1][j]==s[i][j])
        dfs(i+1,j);
    if(j<m-1 && !mk1[i][j+1] && s[i][j+1]==s[i][j])
        dfs(i,j+1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> t;
    for(int i=0;i<n;i++)
        cin >> s[i];

    queue<int> q;
    cont=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(!mk1[i][j])
            {
                dfs(i,j);
                level[cont]=-1;
                if(sz>1)
                {
                    q.push(cont);
                    level[cont]=0;
                    mk[cont]=1;
                }
                sz=0;
                cont++;
            }

    for(int i=1;i<n;i++)
        for(int j=0;j<m;j++)
            if(s[i][j]!=s[i-1][j])
            {
                g[c[i][j]].push_back(c[i-1][j]);
                g[c[i-1][j]].push_back(c[i][j]);
            }
    for(int i=0;i<n;i++)
        for(int j=1;j<m;j++)
            if(s[i][j]!=s[i][j-1])
            {
                g[c[i][j]].push_back(c[i][j-1]);
                g[c[i][j-1]].push_back(c[i][j]);
            }

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(auto v : g[u])
            if(!mk[v])
            {
                mk[v]=1;
                q.push(v);
                level[v]=level[u]+1;
            }
    }

    while(t--)
    {
        ll x,y,p;
        cin >> x >> y >> p;
        x--,y--;
        int ty=c[x][y];
//        db(ty)
//        db(level[ty])
        if(level[ty]==-1 || p<=level[ty])
            db(s[x][y])
        else
        {
            ll v=s[x][y]-'0';
            v+=p-level[ty]+(1ll<<60);
            db(v&1)
        }

//        db("")
    }

    return 0;
}
/**
3 3 3
000
111
000
1 1 1
2 2 2
3 3 3
5 5 3
01011
10110
01101
11010
10101
1 1 4
1 2 3
5 5 3
**/