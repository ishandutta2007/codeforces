#include<cstdio>
#include<algorithm>
#include<unordered_map>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,INF=0x7fffffff;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int n,m,a[N][5],b[N][32],w[N],c[N<<5],id[N],bb[N][32],ans=INF,p[N*5<<5],tot;
struct custom_hash
{
	int operator()(int sb)const
	{
		return sb%202219;
	}
};
unordered_map<int,int,custom_hash> to[N<<5];
bool cmp(int u,int v){return w[u]<w[v];}
inline int calc(int i)
{
	int s=0;
	F(j,0,1<<m)if(__builtin_parity(j))s-=c[b[i][j]];
	else s+=c[b[i][j]];
	return s;
}
void insert(int *t,int u,int i,int mask,int *d)
{
	if(i==m)
	{
		d[mask]=u;
		return;
	}
	if(!to[u][t[i]])to[u][t[i]]=++tot;
	insert(t,u,i+1,mask<<1,d);
	insert(t,to[u][t[i]],i+1,mask<<1|1,d);
}
int main()
{
	read(n,m);
	F(i,0,n)
	{
		F(j,0,m)read(a[i][j]);
		sort(a[i],a[i]+m);
		insert(a[i],0,0,0,b[i]);
		read(w[i]);
		id[i]=i;
	}
	sort(id,id+n,cmp);
	F(i,0,n)F(j,1,1<<m)bb[i][j]=b[i][j];
	F(i,0,n)F(j,1,1<<m)b[i][j]=bb[id[i]][j];
	F(i,0,n)bb[i][0]=w[i];
	F(i,0,n)w[i]=bb[id[i]][0];
	F(i,0,n)F(j,0,1<<m)++c[b[i][j]];
	for(int i=0,j=n;i<n;++i)
	{
		if(calc(i))
		{
			while(calc(i)&&j)
			{
				--j;
				F(k,0,1<<m)--c[b[j][k]];
			}
			ans=min(ans,w[i]+w[j]);
		}
	}
	if(ans==INF)ans=-1;
	printf("%d\n",ans);
	return 0;
}