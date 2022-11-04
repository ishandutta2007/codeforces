#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define eb emplace_back
#define y1 yylyylyylyyl
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef unsigned long long ull;
 
long long read() {
    long long res=0, w=1; char c=getchar();
    while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
    while(isdigit(c)) {res=res*10+c-48, c=getchar();}
    return res*w;
}

const int N=4e5+9,inf=0x3f3f3f3f;
int T,n,m,vst[N],d[N],s,t,w[N],lst[N];
vector<int>v[N];
vector<char>c[N];
char tmp[N];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int cx[4]={1,1,-1,-1};
int cy[4]={-1,1,-1,1};
vi e[N];
int id(int x,int y) {
    if(1<=x&&x<=n&&1<=y&&y<=m&&v[x][y]) return (x-1)*m+y;
    else return 0;
}
pii oid(int x) {
    return pii((x-1)/m+1,x%m==0?m:x%m);
}

void dijkstra() {
    priority_queue<pii> q; q.push(pii(0,s));
    rep(i,1,n*m+2) d[i]=inf, vst[i]=0, lst[i]=0; d[s]=0;
    while(!q.empty()) {
        int u=q.top().se; q.pop();
        if(vst[u]) continue; vst[u]=1;
        for(auto v:e[u]) {
            if(d[v]>d[u]+w[v]) d[v]=d[u]+w[v], q.push(pii(-d[v],v)), lst[v]=u;
        }
    }
    if(d[t]==inf) puts("NO");
    else {
        puts("YES");
        int u=t;
        while(u) {
            if(u==s) break;
            if(u!=t) {
                pii p=oid(u);
                c[p.fi][p.se]='#';
            }
            u=lst[u];
        }
        rep(i,1,n) {
            rep(j,1,m) putchar(c[i][j]);
            puts("");
        }
    }
}

signed main() {
    T=read();
    while(T--) {
        n=read(), m=read();
        s=n*m+1, t=n*m+2;
        rep(i,0,n+1) c[i].clear();
        c[0].resize(m+2), c[n+1].resize(m+2);
        rep(i,1,n) {
            scanf("%s",tmp+1);
            c[i].resize(m+2);
            rep(j,1,m) c[i][j]=tmp[j];
        }
        rep(i,1,n) {
            v[i].resize(m+1);
            rep(j,1,m) {
                v[i][j]=1; 
                rep(k,0,3) v[i][j]&=(c[i+dx[k]][j+dy[k]]!='#');
                if(v[i][j]) {
                    int u=id(i,j);
                    if(c[i][j]=='#') w[u]=0;
                    else w[u]=1;
                }
            }
        }
        rep(i,1,n) {
            rep(j,1,m) {
                rep(k,0,3) {
                    int u=id(i,j), v=id(i+cx[k],j+cy[k]);
                    if(u&&v) e[u].eb(v);
                }
            }
        }
        rep(i,1,n) if(id(i,1)) e[s].eb(id(i,1)), e[id(i,1)].eb(s);
        rep(i,1,n) if(id(i,m)) e[id(i,m)].eb(t), e[t].eb(id(i,m));
        dijkstra();
        rep(i,1,n*m+2) e[i].clear(), e[i].shrink_to_fit();
    }
    return 0;
}