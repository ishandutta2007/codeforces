#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
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
struct query{int l,r,bl,id;}qy[N];
bool operator<(query a,query b){return a.bl!=b.bl?a.bl<b.bl:a.bl&1?a.r<b.r:a.r>b.r;}
int n,b,a[N],q,l,r,c[N],d[N],dl[N],dr[N],x,y,ans[N],f[N];
int main()
{
	read(n);
	while(b*b<n)++b;
	F(i,0,n)++c[read(a[i])];
	F(i,0,N-1)dr[i+1]=dl[i+1]=dl[i]+c[i];
	read(q);
	F(i,0,q)--read(qy[i].l),read(qy[i].r),qy[i].id=i,qy[i].bl=qy[i].l/b;
	sort(qy,qy+q);
	F(i,0,q)
	{
		int l_=qy[i].l,r_=qy[i].r;
		while(l>l_)
		{
			int u=a[--l];
			y-=dl[u]!=dr[u]&&!f[u];
			d[--dl[u]]=l;
			x+=dl[u]+1==dr[u];
			if(dr[u]-dl[u]>2)f[u]+=d[dl[u]+1]*2!=d[dl[u]]+d[dl[u]+2];
			y+=!f[u];
		}
		while(r<r_)
		{
			int u=a[r];
			y-=dl[u]!=dr[u]&&!f[u];
			d[dr[u]++]=r;
			x+=dl[u]+1==dr[u];
			if(dr[u]-dl[u]>2)f[u]+=d[dr[u]-2]*2!=d[dr[u]-1]+d[dr[u]-3];
			y+=!f[u];
			++r;
		}
		while(l<l_)
		{
			int u=a[l];
			y-=!f[u];
			if(dr[u]-dl[u]>2)f[u]-=d[dl[u]+1]*2!=d[dl[u]]+d[dl[u]+2];
			x-=dl[u]+1==dr[u];
			++dl[u];
			y+=dl[u]!=dr[u]&&!f[u];
			++l;
		}
		while(r>r_)
		{
			int u=a[--r];
			y-=!f[u];
			if(dr[u]-dl[u]>2)f[u]-=d[dr[u]-2]*2!=d[dr[u]-1]+d[dr[u]-3];
			x-=dl[u]+1==dr[u];
			--dr[u];
			y+=dl[u]!=dr[u]&&!f[u];
		}
		ans[qy[i].id]=x+!y;
	}
	F(i,0,q)printf("%d\n",ans[i]);
	return 0;
}