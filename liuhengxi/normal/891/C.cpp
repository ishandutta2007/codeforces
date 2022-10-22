#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct line
{
	int u,v,w,id;
	bool operator<(line b)const{return w<b.w;}
}e[N];
int n,m,q,k,u[N],v[N],w[N],f[N],d[N],s[N],g[N],c[N];
bool use[N];
int find(int x,int w){return f[x]==x||d[x]>=w?x:find(f[x],w);}
void merge(int x,int y,int w)
{
	x=find(x,w+1);y=find(y,w+1);
	if(x==y)return;
	if(s[x]<s[y])x^=y^=x^=y;
	s[f[y]=x]+=s[y];d[y]=w;
}
int find(int x){return g[x]==x?x:g[x]=find(g[x]);}
bool cmp(int a,int b){return w[a]<w[b];}
int main()
{
	read(n);read(m);
	F(i,0,m)read(u[i]),read(v[i]),read(w[i]);
	F(i,0,m)e[i].u=--u[i],e[i].v=--v[i],e[i].w=w[i],e[i].id=i;
	sort(e,e+m);
	F(i,0,n)f[i]=i,s[i]=1;
	for(int i=0,j=0;i<m;i=j)
	{
		while(j<m&&e[j].w==e[i].w)++j;
		F(k,i,j)if(find(e[k].u,e[i].w)!=find(e[k].v,e[i].w))
		{
			use[e[k].id]=true;
			merge(find(e[k].u,e[i].w),find(e[k].v,e[i].w),e[i].w);
		}
	}
	read(q);
	while(q--)
	{
		bool ans=true;
		read(k);
		F(i,0,k)read(c[i]),--c[i];
		sort(c,c+k,cmp);
		F(i,0,k)if(!use[c[i]])ans=false;
		for(int i=0,j=0;ans&&i<k;i=j)
		{
			int tmp;
			while(j<k&&w[c[i]]==w[c[j]])++j;
			F(kk,i,j)tmp=find(u[c[kk]],w[c[i]]),g[u[c[kk]]]=g[tmp]=tmp;
			F(kk,i,j)tmp=find(v[c[kk]],w[c[i]]),g[v[c[kk]]]=g[tmp]=tmp;
			F(kk,i,j)if(find(u[c[kk]])==find(v[c[kk]]))ans=false;
			else g[find(u[c[kk]])]=find(v[c[kk]]);
		}
		puts(ans?"YES":"NO");
	}
	return 0;
}