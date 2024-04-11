#include<string>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define INF 2147483647
#define LL long long
#define ULL unsigned long long
#define MAXN 100+300000
#define N 10
#define rep(i,s,t) for(int i=s;i<=t;++i)
#define dwn(i,s,t) for(int i=s;i>=t;--i)
#define lc(x) ch[x][0]
#define rc(x) ch[x][1]
#define wch(x) (rc(fa[x])==x)
using namespace std;
struct splay
{
	int ch[N][2],fa[N],siz[N],ct[N],rt,ed;LL v[N];
	inline int upd(int x){if (x) siz[x]=siz[lc(x)]+ct[x]+siz[rc(x)];}
	inline void rot(int x)
	{
		int f=fa[x],z=fa[f],k=wch(x);
		ch[f][k]=ch[x][k^1],fa[ch[f][k]]=f,fa[f]=x,ch[x][k^1]=f,fa[x]=z;
		if(z) ch[z][f==ch[z][1]]=x;upd(f);upd(x);
	}
	inline void spl(int x){
		for (int y;y=fa[x];rot(x)) if (fa[y]) rot(((wch(x)==wch(y)))?y:x);rt=x;
	}
	inline void fd(LL x){
		int t=rt;while (v[t]!=x && ch[t][x>v[t]]) t=ch[t][x>v[t]];spl(t);
	}
	inline void ins(LL x)
	{
		if (!rt) {rt=ed=1;v[1]=x;ct[1]=siz[1]=1;return;}int t=rt;
		while (v[t]!=x && ch[t][x>v[t]]) siz[t]++,t=ch[t][x>v[t]];
		siz[t]++;if (v[t]==x) {ct[t]++;upd(t);spl(t);return;}ed++;
		ch[t][x>v[t]]=ed;siz[ed]=ct[ed]=1;v[ed]=x;fa[ed]=t;spl(ed);
	}
	inline int qry(LL x,int k)
	{
		fd(x);int t=rt;if ((v[t]>x && k) || (v[t]<x && !k)) return t;
		t=ch[t][k];while (ch[t][k^1]) t=ch[t][k^1];spl(t);return t;
	}
	inline void del(LL x)
	{
		fd(x);int r=rt;if (ct[r]>1) {ct[r]--;return;}qry(x,0);fa[rc(r)]=rt;ch[rt][1]=rc(r);spl(rc(r));
	}
	inline LL frk(LL x){fd(x);return siz[lc(rt)];}
	inline LL krf(LL x)
	{
		int tmp=0,t=rt;
		while (1)
		{//cout<<v[t]<<' '<<x<<' '<<siz[t]<<"  ";
			if (ch[t][0] && x<=siz[ch[t][0]]) t=ch[t][0];
			else
			{
				tmp=siz[ch[t][0]]+ct[t];
				if (x<=tmp) return t;
				x-=tmp,t=ch[t][1];
			}
		}
	}
}bst;
inline int read(){
    int x=0,f=1; char ch=getchar();
    for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
    for(;isdigit(ch);ch=getchar())x=ch-'0'+(x<<3)+(x<<1);
    return x*f;
}

inline void write(int x){
    int t=10,len=1; while(t<=x)t*=10,len++;
    while(len--)t/=10,putchar(x/t+48),x%=t;
    return ;
}

int n,m,mx[11][MAXN],pos[11][MAXN];
void init(){
    n=read(),m=read();
    rep(i,1,m)rep(j,1,n)
        mx[i][j]=read(),pos[i][mx[i][j]]=j;
    return ;
}

LL ans=0,vis[MAXN],now[11];
void work(){
    rep(i,1,n){
        if(vis[mx[1][i]])continue;
        rep(j,1,m)now[j]=pos[j][mx[1][i]];
        int tmp=0; vis[mx[1][i]]=1;
        while(1){
            int tag=1; if(i+tmp>n)break;
            rep(j,1,m){
                if(mx[j][now[j]+tmp]!=mx[1][now[1]+tmp]){tag=0;break;}
            }
            if(!tag)break; tmp++,vis[mx[1][now[1]+tmp-1]]=1;
        }
        ans+=(LL)tmp*(tmp+1)/2;
    }
    cout<<ans<<endl;
    return ;
}

int main(){
    init(); work(); return 0;
}