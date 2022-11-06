#pragma GCC optimize("Ofast","inline") 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using std::swap;
using std::vector;
inline int back2(vector<int> &V)
{
	return V[(int)V.size()-2];
}
const int mod=1e9+7;
inline int add(int a,int b)
{
	return (a+=b)>=mod?a-mod:a;
}
inline int sub(int a,int b)
{
	return (a-=b)<0?a+mod:a;
}
inline int mul(int a,int b)
{
	return (long long)a*b%mod;
}
inline int qpow(int a,int b)
{
	int res=1;
	for(;b;a=mul(a,a),b>>=1)
		if(b&1)
			res=mul(res,a);
	return res;
}
const int N=2e5+5;
int prime[N],tot;
int mu[N],phi[N];
bool isprime[N];
inline void sieve(int n)
{
	register int i,j;
	memset(isprime+1,1,sizeof(bool)*n);
	isprime[1]=0;mu[1]=phi[1]=1;
	for(i=1;i<=n;i++)
	{
		if(isprime[i])
			prime[++tot]=i,mu[i]=sub(0,1),phi[i]=sub(i,1);
		for(j=1;j<=tot&&i*prime[j]<=n;j++)
		{
			isprime[i*prime[j]]=0;
			if(i%prime[j]==0)
			{
				phi[i*prime[j]]=mul(phi[i],prime[j]);
				break;
			}
			mu[i*prime[j]]=sub(0,mu[i]);
			phi[i*prime[j]]=mul(phi[i],phi[prime[j]]);
		}
	}
	return;
}
int n,idx;
int a[N],F[N],f[N],c[N];
int v[N<<1],first[N],next[N<<1];
int id[N],father[N],hson[N],deep[N],size[N],top[N];
vector<int> V[N];
vector<int> S;
void dfs1(int now)
{
	register int go;
	deep[now]=deep[father[now]]+1;size[now]=1;
	for(go=first[now];go;go=next[go])
		if(v[go]!=father[now])
		{
			father[v[go]]=now;
			dfs1(v[go]);
			size[now]+=size[v[go]];
			if(size[v[go]]>size[hson[now]])
				hson[now]=v[go];
		}
	return;
}
void dfs2(int now,int root)
{
	register int go;
	id[now]=++idx;top[now]=root;
	if(hson[now])
		dfs2(hson[now],root);
	for(go=first[now];go;go=next[go])
		if(v[go]!=father[now]&&v[go]!=hson[now])
			dfs2(v[go],v[go]);
	return;
}
inline int lca(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(deep[top[x]]<deep[top[y]])
			swap(x,y);
		x=father[top[x]];
	}
	if(deep[x]<deep[y])
		swap(x,y);
	return y;
}
vector<int> st;
struct edge
{
	int v,w;
	edge(int _v=0,int _w=0)
	{
		v=_v;w=_w;
		return;
	}
};
vector<edge> ch[N];
inline void build_tree()
{
	int x,y;
	register int i;
	st.clear();
	st.push_back(S[0]);
	for(i=1;i<(int)S.size();i++)
	{
		x=S[i];y=lca(st.back(),x);
		while((int)st.size()>1&&deep[back2(st)]>deep[y])
			ch[back2(st)].push_back(edge(st.back(),deep[st.back()]-deep[back2(st)])),st.pop_back();
		if(deep[st.back()]>deep[y])
			ch[y].push_back(edge(st.back(),deep[st.back()]-deep[y])),st.pop_back();
		if(st.empty()||st.back()!=y)
			st.push_back(y);
		if(st.back()!=x)
			st.push_back(x);
	}
	while((int)st.size()>1)
		ch[back2(st)].push_back(edge(st.back(),deep[st.back()]-deep[back2(st)])),st.pop_back();
	return;
}
int res;
int wa[N],wa2[N];//wa2!
void dfs(int now)
{
	register int i;
	wa[now]=phi[a[now]]*c[now];wa2[now]=0;
	for(i=0;i<(int)ch[now].size();i++)
	{
		dfs(ch[now][i].v);
		wa2[ch[now][i].v]=add(wa2[ch[now][i].v],mul(ch[now][i].w,wa[ch[now][i].v]));
		res=add(res,add(mul(wa[now],wa2[ch[now][i].v]),mul(wa2[now],wa[ch[now][i].v])));
		wa[now]=add(wa[now],wa[ch[now][i].v]);wa2[now]=add(wa2[now],wa2[ch[now][i].v]);
	}
	ch[now].clear();
	return;
}
signed main()
{
	register int i,j;
	scanf("%d",&n);
	sieve(n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]),V[a[i]].push_back(i);
	for(i=1;i<=n-1;i++)
	{
		scanf("%d%d",&v[i+n-1],&v[i]);
		next[i]=first[v[i+n-1]];first[v[i+n-1]]=i;
		next[i+n-1]=first[v[i]];first[v[i]]=i+n-1;
	}
	dfs1(1);
	dfs2(1,1);
	for(i=1;i<=n;i++)
	{
		S.clear();
		for(j=i;j<=n;j+=i)
			S.insert(S.end(),V[j].begin(),V[j].end());
		sort(S.begin(),S.end(),[&](int x,int y)->bool
		{
			return id[x]<id[y];
		});
		for(j=0;j<(int)S.size();j++)
			c[S[j]]=1;
		build_tree();
		res=0;dfs(st[0]);
		F[i]=res;
		for(j=0;j<(int)S.size();j++)
			c[S[j]]=0;
	}
	for(i=1;i<=n;i++)
		for(j=1;i*j<=n;j++)
			f[i]=add(f[i],mul(mu[j],F[i*j]));
	int ans=0;
	for(i=1;i<=n;i++)
		ans=add(ans,mul(mul(i,qpow(phi[i],mod-2)),f[i]));
	ans=mul(2,ans);
	ans=mul(ans,qpow(mul(n,n-1),mod-2));
	printf("%d\n",ans);
	return 0;
}