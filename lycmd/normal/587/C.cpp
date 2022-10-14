#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast")
#define GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx512f,ture=native")
#include<bits/stdc++.h>
#define gc() (uu==vv&&(vv=(uu=cc)+fread(cc,1,1<<21,stdin),uu==vv)?EOF:*uu++)
#define pc(c) (*o++=(c))
using namespace std;
typedef vector<int> node;
int const N=200010,M=10000010;
struct edge{int t,nxt;}e[N<<1];
int n,m,q,tot,head[N],dep[N],f[N][23],lg[N],cnt[N];
node tr[N][23];
char cc[M],*uu=cc,*vv=cc,buf[M],*p1=buf,*p2=buf,obuf[M],*o=obuf;
inline int read(){
	char ch=gc();int X=0;bool fl=0;
	while(ch<'0'||ch>'9'){if(ch=='-')fl=1;ch=gc();}
	while(ch>='0'&&ch<='9'){X=(X<<1)+(X<<3)+ch-'0';ch=gc();}
	if(fl)return ~(X-1);
	return X;
}
void write(int x){
	if(x<0)pc('-'),x=-x;
	if(x>9)write(x/10);
	pc((x%10)|48);
}
void merge(node&x,node y){
	vector<int>ans;
	int p1=0,p2=0;
	while(p1<x.size()&&p2<y.size()&&ans.size()<10){
		if(x[p1]>y[p2])
			ans.push_back(y[p2++]);
		else
			ans.push_back(x[p1++]);
	}
	while(p1<x.size()&&ans.size()<10)
		ans.push_back(x[p1++]);
	while(p2<y.size()&&ans.size()<10)
		ans.push_back(y[p2++]);
	x=ans;
}
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x,int fa){
	f[x][0]=fa;
	dep[x]=dep[fa]+1;
	for(int i=1;i<=lg[dep[x]];i++)
		f[x][i]=f[f[x][i-1]][i-1],
		merge(tr[x][i],tr[x][i-1]),
		merge(tr[x][i],tr[f[x][i-1]][i-1]);
	for(int i=head[x];i;i=e[i].nxt)
		if(e[i].t!=fa)
			dfs(e[i].t,x);
}
int lca(int x,int y){
	if(dep[x]<dep[y])
		swap(x,y);
	while(dep[x]>dep[y])
		x=f[x][lg[dep[x]-dep[y]]-1];
	if(x==y)return x;
	for(int k=lg[dep[x]]-1;k>=0;k--)
		if(f[x][k]!=f[y][k])
			x=f[x][k],y=f[y][k];
	return f[x][0];
}
node jump(int x,int y){
	node res;
	while(dep[x]>dep[y])
		merge(res,tr[x][lg[dep[x]-dep[y]]-1]),
		x=f[x][lg[dep[x]-dep[y]]-1];
	return res;
}
int main(){
	n=read(),m=read(),q=read();
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		add(x,y);add(y,x);
	}
	for(int i=1;i<=m;i++){
		int x=read();
		if(tr[x][0].size()<11)
			tr[x][0].push_back(i);
	}
	for(int i=1;i<=n;i++)
		lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	dfs(1,0);
	while(q--){
		int x=read(),y=read(),a=read(),l=lca(x,y);
		node res;merge(res,tr[l][0]);
		merge(res,jump(x,l)),merge(res,jump(y,l));
		while(res.size()>a)
			res.pop_back();
		write(res.size()),pc(32);
		for(int i:res)write(i),pc(32);
		pc(10);
	}
	fwrite(obuf,o-obuf,1,stdout);
}