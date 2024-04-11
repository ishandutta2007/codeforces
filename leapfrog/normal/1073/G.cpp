//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
const int N=200005,Z=26;vector<int>v[N<<1];int ru[N<<1],rut;
struct node{int ch[Z],len,fa;}S[N<<1];int sls,smt,fa[N<<1][19],dep[N<<1];
int id[N],dt,dfn[N<<1],s1[N<<1],s2[N<<1],st[N],tp,n,Q;ll rs=0;
struct edge{int to,nxt;}e[N<<2];int et,head[N<<1],at,a[N<<1];char ch[N];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline char cmp(int a,int b) {return dfn[a]<dfn[b];}
inline void saminit() {sls=smt=1;}
inline void samins(int c)
{
	int p=sls,np=sls=++smt;S[np].len=S[p].len+1;
	for(;p&&!S[p].ch[c];p=S[p].fa) S[p].ch[c]=np;
	int q=S[p].ch[c];if(!p) return S[np].fa=1,void();
	if(S[p].len+1==S[q].len) return S[np].fa=q,void();
	int nq=++smt;S[nq]=S[q],S[nq].len=S[p].len+1,S[q].fa=S[np].fa=nq;
	for(;p&&S[p].ch[c]==q;p=S[p].fa) S[p].ch[c]=nq;
}
inline void dfs0(int x,int f)
{
	dep[x]=dep[f]+1,dfn[x]=++dt,fa[x][0]=f;
	for(int i=1;i<19;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for(auto i:v[x]) dfs0(i,x);
}
inline void init()
{
	for(int i=2;i<=smt;i++) v[S[i].fa].push_back(i);
	dfs0(1,0);for(int i=n,p=1;i;i--) id[i]=p=S[p].ch[ch[i]-'a'];
	//for(int i=2;i<=smt;i++) printf("%d %d\n",S[i].fa,i);
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int d=dep[x]-dep[y],i=0;d;d>>=1,i++) if(d&1) x=fa[x][i];
	if(x==y) return x;
	for(int i=18;~i;i--) if(fa[x][i]^fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
inline void dfs(int x,int fa)
{
	int tmp=s1[x];for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs(e[i].to,x);
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) s1[x]+=s1[e[i].to],s2[x]+=s2[e[i].to];
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) rs+=1ll*s1[e[i].to]*(s2[x]-s2[e[i].to])*S[x].len;
	rs+=1ll*tmp*s2[x]*S[x].len;
}
int main()
{
	saminit(),read(n),read(Q),scanf("%s",ch+1);
	for(int i=n;i;i--) samins(ch[i]-'a');
	init();for(int p,q;Q--;)
	{
		read(p),read(q),at=0,st[tp=1]=1,head[1]=0,et=0,rut=0;
		for(int i=1,x;i<=p;i++) read(x),x=id[x],s1[x]++,a[++at]=x;
		for(int i=1,x;i<=q;i++) read(x),x=id[x],s2[x]++,a[++at]=x;
		sort(a+1,a+at+1,cmp),at=unique(a+1,a+at+1)-a-1;for(int i=1;i<=at;i++) ru[++rut]=a[i];
		for(int i=1;i<=at;a[i]^1?st[++tp]=a[i++]:++i)
		{
			if(a[i]==1) continue;else head[a[i]]=0;
			int lc=LCA(a[i],st[tp]);if(lc==st[tp]) continue;else ru[++rut]=lc;
			while(dfn[lc]<dfn[st[tp-1]]) adde(st[tp-1],st[tp]),adde(st[tp],st[tp-1]),tp--;
			if(dfn[lc]==dfn[st[tp-1]]) adde(lc,st[tp]),adde(st[tp],lc),tp--;
			else head[lc]=0,adde(lc,st[tp]),adde(st[tp],lc),st[tp]=lc;
		}
		for(int i=1;i<tp;i++) adde(st[i],st[i+1]),adde(st[i+1],st[i]);
		rs=0,dfs(1,0),printf("%lld\n",rs);for(int i=1;i<=rut;i++) s1[ru[i]]=s2[ru[i]]=0;
	}
	return 0;
}