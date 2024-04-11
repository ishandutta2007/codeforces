#include<bits/stdc++.h>
std::mt19937 rng(20030417^std::chrono::steady_clock::now().time_since_epoch().count());
template<class T> inline T rand(T l,T r){return std::uniform_int_distribution<T>(l,r)(rng);}
template<class T> inline void read(T &x){
	x=0; char c=getchar(); bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar(); if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10); putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
const int N=2e5+10,M=N*150;
int ___;
int n,m,pos,lim,p[N],fa[N],siz[N],top[N],id[N],dep[N],val[N],son[N],wid[N],Eu[N],Ev[N],Ew[N];
long long ans,sum[N],dis[N],out[N];
std::vector<int> G[N];
namespace SegmentTree{
#define mid ((l+r)>>1)
	int nod,rt[N];
#pragma pack (1)
	struct Node{ //pack to 128b
		unsigned int lc:26,rc:26,tag:19;
		unsigned long long sum:57;
	}e[M];
#pragma pack ()
	void build(int &u,int l,int r){
		int t;
		u=++nod;
		if(l==r)return;
		build(t,l,mid),e[u].lc=t;
		build(t,mid+1,r),e[u].rc=t;
	}
	void modify(int &u,int v,int ql,int qr,int x,int l,int r){
		int t;
		if(v<=lim){
			if(nod+2>M){
				printf("!%d\n",___);
				exit(0);
			}
			e[u=++nod]=e[v];
		}else{
			u=v;
		}
		// if(l==1&&r==n)printf("modify[%d->%d] %d %d %d\n",v,u,ql,qr,x);
		if(ql==l&&qr==r){
			e[u].tag+=x;
			e[u].sum+=x*(sum[r]-sum[l-1]);
			return;
		}
		if(qr<=mid){
			modify(t,e[v].lc,ql,qr,x,l,mid),e[u].lc=t;
		}else if(ql>mid){
			modify(t,e[v].rc,ql,qr,x,mid+1,r),e[u].rc=t;
		}else{
			modify(t,e[v].lc,ql,mid,x,l,mid),e[u].lc=t;
			modify(t,e[v].rc,mid+1,qr,x,mid+1,r),e[u].rc=t;
		}
		e[u].sum=e[u].tag*(sum[r]-sum[l-1])+e[e[u].lc].sum+e[e[u].rc].sum;
	}
	long long query(int u,int ql,int qr,int l,int r){
		// if(l==1&&r==n)printf("query[%d] %d %d\n",u,ql,qr);
		if(!u)return 0;
		if(ql==l&&qr==r)return e[u].sum;
		long long res=(sum[qr]-sum[ql-1])*e[u].tag;
		if(qr<=mid)return res+query(e[u].lc,ql,qr,l,mid);
		if(ql>mid)return res+query(e[u].rc,ql,qr,mid+1,r);
		return res+query(e[u].lc,ql,mid,l,mid)+query(e[u].rc,mid+1,qr,mid+1,r);
	}
#undef mid
}
using namespace SegmentTree;
void dfs(int u){
	siz[u]=1;
	for(int v:G[u])if(v!=fa[u]){
		fa[v]=u,dep[v]=dep[u]+1,dfs(v),siz[u]+=siz[v];
		if(siz[v]>=siz[son[u]])son[u]=v;
	}
}
void dfs(int u,int tpt){
	dis[u]=dis[fa[u]]+val[u];
	top[u]=tpt,id[u]=++pos,wid[id[u]]=u;
	if(siz[u]==1)return;
	dfs(son[u],top[u]);
	for(int v:G[u])if(v!=fa[u]&&v!=son[u])dfs(v,v);
}
void modify(int k,int x,int v){
	while(x){
		modify(rt[k],rt[k],id[top[x]],id[x],v,1,n);
		x=fa[top[x]];
	}
}
long long query(int k,int x){
	int _k=k,_x=x;
	long long res=0;
	while(x){
		res+=query(rt[k],id[top[x]],id[x],1,n);
		x=fa[top[x]];
	}
	// printf("query(%d,%d) => %lld\n",_k,_x,res);
	return res;
}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
	printf("%d\n",sizeof(Node));
	return 0;
#endif
	read(n),read(m);
	for(int i=1;i<=n;i++)read(p[i]);
	for(int i=1;i<n;i++){
		read(Eu[i]),read(Ev[i]),read(Ew[i]);
		G[Eu[i]].push_back(Ev[i]);
		G[Ev[i]].push_back(Eu[i]);
	}
	for(int i=1;i<=n;i++){
		G[i].reserve(G[i].size());
		std::shuffle(G[i].begin(),G[i].end(),rng);
	}
	dep[1]=1,dfs(1);
	for(int i=1;i<n;i++){
		val[dep[Eu[i]]<dep[Ev[i]]?Ev[i]:Eu[i]]=Ew[i];
	}
	dfs(1,1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+val[wid[i]];
	for(int i=1;i<=n;i++){
		rt[i]=rt[i-1],modify(i,p[i],1),lim=nod;
		out[i]=out[i-1]+dis[p[i]];
	}
	for(int o,l,r,x,i=1;i<=m;i++){
		___=i;
		ans&=(1<<30)-1;
		if(read(o),o==1){
			read(l),read(r),read(x),l^=ans,r^=ans,x^=ans;
			// printf(">>> query %d %d %d ==> %lld %lld\n",l,r,x,out[r]-out[l-1],dis[x]*(r-l+1));
			print(ans=out[r]-out[l-1]+dis[x]*(r-l+1)-((query(r,x)-query(l-1,x))<<1),'\n');
		}else{
			read(x),x^=ans;
			// printf(">>> modify %d\n",x);
			rt[x]=rt[x-1],modify(x,p[x+1],1),lim=nod;
			out[x]+=dis[p[x+1]]-dis[p[x]];
			std::swap(p[x],p[x+1]);
		}
		if(i==(m>>1)){
			lim=nod=0,memset(rt,0,sizeof(rt)),memset(e,0,sizeof(e));
			for(int i=1;i<=n;i++){
				rt[i]=rt[i-1],modify(i,p[i],1),lim=nod;
			}
		}
	}
}