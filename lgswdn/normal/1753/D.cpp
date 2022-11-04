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

const int N=6e5+9,inf=2e18;
int n,m,cnt,p,q,d[N],vst[N];
char t[N];
vector<char>s[N];

vp e[N];

int id(int x,int y) {
    if(x<1||x>n||y<1||y>m||s[x][y]=='#') return 0;
    else return (x-1)*m+y;
}
void add(int u,int v,int w) {
    e[u].eb(pii(v,w));
}
void addh(int x1,int y1,int x2,int y2,int w) {
    int u=id(x1,y1), v=id(x2,y2);
    if(u&&v) add(u,v,w);
}

void dijkstra() {
    priority_queue<pii>q;
    d[0]=inf;
    rep(i,1,n) rep(j,1,m) {
        int x=id(i,j);
        if(!x) continue;
        if(s[i][j]=='.') d[x]=0, q.push(pii(0,x));
        else d[x]=inf;
    }
    while(!q.empty()) {
        int u=q.top().se; q.pop();
        if(vst[u]) continue; vst[u]=1;
        for(auto ed:e[u]) {
            int v=ed.fi, w=ed.se;
            if(d[u]+w<d[v]) d[v]=d[u]+w, q.push(pii(-d[v],v));
        }
    }
    d[0]=inf;
}

signed main() {
    n=read(), m=read(), p=read(), q=read();
    rep(i,1,n) {
        scanf("%s",t+1);
        s[i].resize(m+1);
        rep(j,1,m) s[i][j]=t[j], cnt+=(s[i][j]=='.');
    }
    if(cnt<2) {
        puts("-1");
        return 0;
    }
    bool flag=0;
    rep(i,1,n) {
        rep(j,1,m-1) if(s[i][j]=='.'&&s[i][j+1]=='.') flag=1;
    }
    rep(i,1,n-1) {
        rep(j,1,m) if(s[i][j]=='.'&&s[i+1][j]=='.') flag=1;
    }
    if(flag==1) {
        puts("0");
        return 0;
    }
    rep(i,1,n) rep(j,1,m) {
        if(s[i][j]=='L') {
            addh(i-1,j,i,j+1,p);
            addh(i+1,j,i,j+1,p);
            addh(i-1,j+1,i,j,p);
            addh(i+1,j+1,i,j,p);
            addh(i,j-1,i,j+1,q);
            addh(i,j+2,i,j,q);
        }
        if(s[i][j]=='U') {
            addh(i,j-1,i+1,j,p);
            addh(i,j+1,i+1,j,p);
            addh(i+1,j-1,i,j,p);
            addh(i+1,j+1,i,j,p);
            addh(i-1,j,i+1,j,q);
            addh(i+2,j,i,j,q);
        }
    }
    dijkstra();
    int ans=inf;
    rep(i,1,n) {
        rep(j,1,m-1) ans=min(ans,d[id(i,j)]+d[id(i,j+1)]);
    }
    rep(i,1,n-1) {
        rep(j,1,m) ans=min(ans,d[id(i,j)]+d[id(i+1,j)]);
    }
    if(ans==inf) return puts("-1"), 0;
    printf("%lld\n",ans);
    return 0;
}