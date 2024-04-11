#include<stdio.h>
#include<vector>
char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<21],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
using namespace std;
const int maxn=1000005,maxk=21;
int n,m,rt,ans,dfns,mx;
int f[maxn],g[maxn],in[maxn],dep[maxn],st[maxn<<1][maxk],lg[maxn<<1],res[maxn][2],suf[maxn][2];
vector<int>v[maxn];
void read(int &x){
	x=0;
	char c=getchar();
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
		x=x*10+c-48;
}
void dfs1(int x,int last){
	dep[x]=dep[last]+1,in[x]=++dfns,st[dfns][0]=x;
	if(v[x].size()==1){
		f[x]=0;
		return ;
	}
	f[x]=1e9;
	for(int i=0;i<v[x].size();i++){
		int y=v[x][i];
		if(y!=last)
			dfs1(y,x),f[x]=min(f[x],f[y]+1),st[++dfns][0]=x;
	}
}
void dfs2(int x,int last){
	if(last==0)
		g[x]=f[x];
	else g[x]=min(g[last],f[last])+1;
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=last)
			dfs2(v[x][i],x);
}
inline int calc(int a,int b){
	return dep[a]<dep[b]? a:b;
}
inline int lca(int a,int b){
	if(in[a]>in[b])
		swap(a,b);
	int l=in[a],r=in[b],k=lg[r-l+1];
	return calc(st[l][k],st[r-(1<<k)+1][k]);
}
inline int get(int a,int b){
	return dep[a]+dep[b]-2*dep[lca(a,b)];
}
void merge(int *a,int *b){
	if(a[0]==0){
		a[0]=b[0],a[1]=b[1];
		return ;
	}
	if(b[0]==0)
		return ;
	int res=get(a[0],a[1]),c[2]={a[0],a[1]};
	for(int i=0;i<=1;i++)
		for(int j=0;j<=1;j++){
			int v=get(a[i],b[j]);
			if(v>res)
				res=v,c[0]=a[i],c[1]=b[j];
		}
	int v=get(b[0],b[1]);
	if(v>res)
		res=v,c[0]=b[0],c[1]=b[1];
	a[0]=c[0],a[1]=c[1];
}
int check(int d,int x,int lim){
	int d0=max(0,lim-d-x);
	if(d0>mx)
		return 0;
	int mx=0;
	for(int i=0;i<=1;i++)
		for(int j=0;j<=1;j++)
			mx=max(mx,get(res[d][i],suf[d0][j]));
	return mx>=lim;
}
int main(){
	read(n);
	for(int i=2,x;i<=n;i++)
		read(x),v[x].push_back(i),v[i].push_back(x);
	for(int i=1;i<=n;i++)
		if(v[i].size()>1)
			rt=i;
	dfs1(rt,0),dfs2(rt,0);
	lg[0]=-1;
	for(int i=1;i<=dfns;i++)
		lg[i]=lg[i>>1]+1;
	for(int i=1;i<=20;i++)
		for(int j=1;j+(1<<i)-1<=dfns;j++)
			st[j][i]=calc(st[j][i-1],st[j+(1<<(i-1))][i-1]);
	for(int i=1;i<=n;i++){
		int c[2]={i,i},k=min(f[i],g[i]);
		merge(res[k],c),mx=max(mx,k);
	}
	suf[mx][0]=res[mx][0],suf[mx][1]=res[mx][1];
	for(int i=mx-1;i>=0;i--)
		suf[i][0]=res[i][0],suf[i][1]=res[i][1],merge(suf[i],suf[i+1]);
	read(m);
	for(int t=1,x;t<=m;t++){
		read(x),ans=0;
		for(int i=0;i<=mx;i++)
			while(check(i,x,ans+1))
				ans++;
		printf("%d%c",ans,t==m? '\n':' ');
	}
	return 0;
}