#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename T> bool chkmin(T &x,T y){return y<x?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template <typename T> void readint(T &x)
{
	int f=1;char c;x=0;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
const int MOD=1000000007;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=750005;

int n,m;
pii e[MAXN];bool ins[MAXN];
int ch[MAXN][2],fa[MAXN],sz[MAXN];
bool rev[MAXN];
int sum[MAXN],hv[MAXN],col[MAXN],tag[MAXN];
bool nroot(int x){return ch[fa[x]][0]==x || ch[fa[x]][1]==x;}
bool sonr(int x){return ch[fa[x]][1]==x;}
void reverse(int x){rev[x]^=1;swap(ch[x][0],ch[x][1]);}
void cover(int x,int c){sum[x]=sz[x],hv[x]=(x>n),col[x]=c,tag[x]=1;}
void clean(int x){sum[x]=0,hv[x]=0,col[x]=0,tag[x]=-1;}
void pushdown(int x)
{
	if(rev[x])reverse(ch[x][0]),reverse(ch[x][1]),rev[x]=0;
	if(tag[x]==1)cover(ch[x][0],col[x]),cover(ch[x][1],col[x]),tag[x]=0;
	else if(tag[x]==-1)clean(ch[x][0]),clean(ch[x][1]),tag[x]=0;
}
void pushall(int x){if(nroot(x))pushall(fa[x]);pushdown(x);}
void update(int x)
{
	sum[x]=sum[ch[x][0]]+sum[ch[x][1]]+hv[x];
	sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+(x>n);
}
void rotate(int x)
{
	int y=fa[x],z=fa[y],ty=sonr(x),s=ch[x][ty^1];
	if(nroot(y))ch[z][sonr(y)]=x;
	ch[x][ty^1]=y,ch[y][ty]=s;
	fa[x]=z,fa[y]=x;
	if(s)fa[s]=y;
	update(y),update(x);
}
void splay(int x)
{
	pushall(x);
	while(nroot(x))
		if(!nroot(fa[x]))rotate(x);
		else if(sonr(x)==sonr(fa[x]))rotate(fa[x]),rotate(x);
		else rotate(x),rotate(x);
}
void access(int x){for(int y=0;x;x=fa[y=x])splay(x),ch[x][1]=y,update(x);}
void makeroot(int x){access(x);splay(x);reverse(x);}
void link(int x,int y){makeroot(x);makeroot(y);fa[x]=y;}
void cut(int x,int y){makeroot(x);access(y);splay(x);ch[x][1]=fa[y]=0;update(x);}

bool nok(int x,int y)
{
	makeroot(x),access(y),splay(y),splay(x);
	return nroot(y) && sum[x];
}
void insert(int t)
{
	int x=e[t].x,y=e[t].y;
	makeroot(x),access(y),splay(y),splay(x);
	if(!nroot(y))link(x,t+n),link(y,t+n),ins[t]=1;
	else cover(x,t);
}
void erase(int t)
{
	int x=e[t].x,y=e[t].y;
	if(!ins[t])makeroot(x),access(y),splay(y),clean(y);
	else
	{
		splay(t+n);
		if(col[t+n])
		{
			int s=col[t+n];
			int u=e[s].x,v=e[s].y;
			makeroot(u),access(v),splay(v),clean(v);
			cut(t+n,x),cut(t+n,y),ins[t]=0;
			insert(s);
		}
		else cut(t+n,x),cut(t+n,y),ins[t]=0;
	}
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
	#endif
	readint(n),readint(m);
	for(int i=1;i<=m;++i)readint(e[i].x),readint(e[i].y);
	for(int i=1;i<=n+m;++i)sz[i]=1;
	ll res=0;
	for(int l=1,r=1;r<=m;++r)
	{
		while(l<=r && nok(e[r].x,e[r].y))erase(l),++l;
		insert(r);
		res+=r-l+1;
	}
	printf("%lld\n",res);
	return 0;
}