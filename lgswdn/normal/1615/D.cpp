#include<bits/stdc++.h>
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

const int N=2e6+9;

int n,m,eu[N],ev[N],ww[N],s[N],sx[N],f[N];
vp ee[N];

struct edge{int to,nxt;}e[N*2]; int hd[N],tot;
void add(int u,int v) {
    e[++tot]=(edge){v,hd[u]}; hd[u]=tot;
}
int tick,dfn[N],low[N],cnt,scc[N],sz[N];
bool in[N]; 
stack<int>st;
void tarjan(int u){
    dfn[u]=low[u]=++tick;
    st.push(u), in[u]=1;
    int p=u; if(p>n) p-=n;
    if(s[p]==-1) {
        if(u>n) s[p]=1;
        else s[p]=0;
    }
    for(int i=hd[u],v;i;i=e[i].nxt) {
        if(!dfn[(v=e[i].to)])
            tarjan(v),low[u]=min(low[u],low[v]);
        else if(in[v])
            low[u]=min(low[u],low[v]);
    }
    if(dfn[u]==low[u]) {
        int v=0; in[u]=0; scc[u]=++cnt; sz[cnt]++;
        while(st.top()!=u) {
            int v=st.top(); st.pop();
            in[v]=0; scc[v]=cnt; sz[cnt]++;
        }
        st.pop();
    }
}

void ad(int u,int v,int t) {
    if(t==0) {
        add(u,v), add(v,u), add(u+n,v+n), add(v+n,u+n);
    } else {
        add(u,v+n), add(v+n,u), add(u+n,v), add(v,u+n);
    }
}

void dfs(int u,int fa) {
    f[u]=fa;
    for(auto ed:ee[u]) if(ed.fi!=fa) sx[ed.fi]=ed.se, dfs(ed.fi,u);
}

void calc() {
    rep(i,1,n) if(scc[i]==scc[i+n]) {
        puts("NO");
        return;
    }
    puts("YES");
    dfs(1,0);
    rep(i,2,n) {
        printf("%d %d ",i,f[i]);
        if(sx[i]==-1) printf("%d\n",s[f[i]]^s[i]);
        else printf("%d\n",sx[i]);
    }
}

signed main() {
    int T=read();
    while(T--) {
        n=read(), m=read();
        rep(i,1,n*2) hd[i]=0, s[i]=-1, dfn[i]=scc[i]=low[i]=in[i]=sz[i]=0; tot=1, tick=0, cnt=0;
        rep(u,1,n) ee[u].clear(), ee[u].shrink_to_fit();
        while(!st.empty()) st.pop();
        rep(i,2,n) {
            int u=read(), v=read(), w=read();
            eu[i]=u, ev[i]=v, ww[i]=w;
            if(ww[i]!=-1) {
                int pc=__builtin_popcount(w)%2;
                ad(u,v,pc);
            }
            ee[u].emplace_back(pii(v,w)), ee[v].emplace_back(pii(u,w));
        }
        rep(i,1,m) {
            int u=read(), v=read(), t=read();
            ad(u,v,t);
        }
        rep(i,1,n*2) if(scc[i]==0) tarjan(i);
        calc();
    }
    return 0;
}