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
typedef unsigned long long ull;

long long read() {
    long long res=0, w=1; char c=getchar();
    while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
    while(isdigit(c)) {res=res*10+c-48, c=getchar();}
    return res*w;
}

const int N=2e5+9,inf=1e9;
char t[N];
int n,s[N],ans;

namespace SufT {
    int n,tot,st[N],l[N],link[N],ch[N][29],dep[N],now,r,sz[N];
    void init() {
        l[0]=inf, tot=now=1, n=r=0;
    }
    int newn(int stt,int len=inf) {
        ++tot;
        link[tot]=1, l[tot]=len, st[tot]=stt;
        return tot;
    }
    void extend(int x) {
        n++, r++; int last=1;
        while(r) {
            while(r>l[ch[now][s[n-r+1]]])
                now=ch[now][s[n-r+1]], r-=l[now];
            int &v=ch[now][s[n-r+1]], c=s[st[v]+r-1];
            if(x==c||!v) {
                link[last]=now, last=now;
                if(!v) v=newn(n-r+1);
                else return;
            } else {
                int u=newn(st[v],r-1);
                ch[u][c]=v, ch[u][x]=newn(n);
                st[v]+=r-1, l[v]-=r-1;
                v=u, link[last]=u, last=u;
            }
            if(now==1) r--; else now=link[now];
        }
    }
    void getlen() {
        rep(i,1,tot) if(l[i]>n) l[i]=n-st[i];
    }
    void dfs(int u) {
        rep(i,0,26) {
            int v=ch[u][i]; if(!v) continue;
            dep[v]=dep[u]+l[v];
            dfs(v);
            sz[u]+=sz[v];
            ans+=sz[v]*(sz[v]+1)/2*l[v];
        }
        if(!sz[u]) sz[u]=1;
    }
}

signed main() {
    scanf("%s",t+1); n=strlen(t+1); t[++n]='a'+26;
    SufT::init();
    rep(i,1,n) {
        s[i]=t[i]-'a';
        SufT::extend(s[i]);
    }
    SufT::getlen();
    SufT::dfs(1);
    printf("%lld\n",ans);
    return 0;
}