#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<bitset>

#define pb push_back
#define mp make_pair

using namespace std;

template<typename T>inline void upmin(T &x,T y) { y<x?x=y:0; }
template<typename T>inline void upmax(T &x,T y) { x<y?x=y:0; }

typedef unsigned int u32;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double lod;
typedef pair<int,int> PR;
typedef vector<int> VI;

const lod pi=acos(-1);
const int oo=1<<30;
const LL OO=1e18;

const int N=2e5+100;

int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}

char c[N];
int head[N],nxt[N*2],to[N*2];
int siz[N],all,mi,rt;
bool in[N];
inline void dfs1(int k,int fa) {
	siz[k]=1;
	for (int i=head[k];i;i=nxt[i])
		if (to[i]!=fa&&!in[to[i]])
			dfs1(to[i],k),siz[k]+=siz[to[i]];
}
inline void dfs2(int k,int fa) {
	int mx=all-siz[k];
	for (int i=head[k];i;i=nxt[i])
		if (to[i]!=fa&&!in[to[i]])
			dfs2(to[i],k),upmax(mx,siz[to[i]]);
	if (mx<mi)
		mi=mx,rt=k;
}
int tot[1<<20];
LL ans[N];
inline void dfs3(int k,int fa,int s,int d) {
	s^=1<<(c[k]-'a');
	tot[s]+=d;
	for (int i=head[k];i;i=nxt[i])
		if (to[i]!=fa&&!in[to[i]])
			dfs3(to[i],k,s,d);
}
inline LL dfs4(int k,int fa,int s) {
	s^=1<<(c[k]-'a');
	LL w=tot[s];
	for (int i=0;i<20;i++)
		w+=tot[s^(1<<i)];
	for (int i=head[k];i;i=nxt[i])
		if (to[i]!=fa&&!in[to[i]])
			w+=dfs4(to[i],k,s);
	ans[k]+=w;
	return w;
}
inline void dfs(int k) {
	dfs1(k,0);
	all=mi=siz[k];
	dfs2(k,0);
	in[k=rt]=true;
	for (int i=head[k];i;i=nxt[i])
		if (!in[to[i]])
			dfs3(to[i],k,0,1);
	int s=1<<(c[k]-'a');
	++tot[0];
	LL sum=1+tot[s];
	for (int i=0;i<20;i++) sum+=tot[s^(1<<i)];
	for (int i=head[k];i;i=nxt[i])
		if (!in[to[i]]) {
			dfs3(to[i],k,0,-1);
			sum+=dfs4(to[i],k,s);
			dfs3(to[i],k,0,1);
		}
	ans[k]+=sum>>1;
	for (int i=head[k];i;i=nxt[i])
		if (!in[to[i]])
			dfs3(to[i],k,0,-1);
	--tot[0];
	for (int i=head[k];i;i=nxt[i])
		if (!in[to[i]])
			dfs(to[i]);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int n=gi(),i,a,b,tot=0;
	for (i=1;i<n;i++) {
		a=gi(),b=gi();
		to[++tot]=b,nxt[tot]=head[a],head[a]=tot;
		to[++tot]=a,nxt[tot]=head[b],head[b]=tot;
	}
	scanf("%s",c+1);
	dfs(1);
	for (i=1;i<=n;i++)
		printf("%I64d ",ans[i]);
	return 0;
}