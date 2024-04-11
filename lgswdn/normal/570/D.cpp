#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

long long read() {
    long long res=0, w=1; char c=getchar();
    while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
    while(isdigit(c)) {res=res*10+c-48, c=getchar();}
    return res*w;
}

const int N=5e5+9;
int n,m,dfn[N],tick,d[N],st[N],ed[N],sz[N],a[N];
vi e[N],df[N],s[N];
char c[N];
void dfs(int u) {
    a[u]=1<<(c[u]-'a'); if(!d[u]) d[u]=1; sz[u]=1;
    dfn[u]=++tick; df[d[u]].emplace_back(dfn[u]), s[d[u]].emplace_back(a[u]);
    for(auto v:e[u]) d[v]=d[u]+1, dfs(v), sz[u]+=sz[v];
}

signed main() {
    n=read(), m=read();
    rep(i,2,n) e[read()].emplace_back(i);
    scanf("%s",c+1);
    dfs(1);
    rep(i,1,n) for(int j=1;j<s[i].size();j++) s[i][j]^=s[i][j-1];
    rep(i,1,m) {
        int a=read(), b=read();
        int l=lower_bound(df[b].begin(),df[b].end(),dfn[a])-df[b].begin();
        int r=upper_bound(df[b].begin(),df[b].end(),dfn[a]+sz[a]-1)-df[b].begin()-1;
        puts((r<=0||__builtin_popcount(s[b][r]^(l?s[b][l-1]:0))<=1)?"Yes":"No");
    }
    return 0;
}