// LUOGU_RID: 90518805
#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
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
constexpr int N=1005;
constexpr long long gcd(long long x,long long y){return !y?x:gcd(y,x%y);}
template<typename T>struct point
{
	T x,y,z;
	friend point operator-(point a,point b)
	{
		return point({a.x-b.x,a.y-b.y,a.z-b.z});
	}
	friend point operator*(point a,point b)
	{
		return point({a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x});
	}
	operator bool(){return x||y||z;}
};
using pointi=point<int>;
using pointl=point<long long>;
pointl conv(pointi x){return pointl({x.x,x.y,x.z});}
struct line
{
	pointi p0,p1;
}l[N];
bool on_same_plane(line a,line b)
{
	pointl A=conv(a.p0),B=conv(a.p1),C=conv(b.p0),D=conv(b.p1);
	return !(((B-A)*(C-A))*((B-A)*(D-A)));
}
bool parallel(line a,line b)
{
	pointl A=conv(a.p0),B=conv(a.p1),C=conv(b.p0),D=conv(b.p1);
	return !((B-A)*(D-C));
}
void get_intersection(line a,line b,long long &num,long long &den)
{
	pointl A=conv(a.p0),B=conv(a.p1),C=conv(b.p0),D=conv(b.p1);
	pointl E=(B-A)*(C-A);
	pointl F=(B-A)*(D-A);
	if(E.x!=F.x)num=C.z*F.x-D.z*E.x,den=F.x-E.x;
	else num=C.z*F.y-D.z*E.y,den=F.y-E.y;
	long long g=gcd(num,den);
	num/=g;den/=g;
	if(den<0)num*=-1,den*=-1;
}
pointl d[N];
int n,f[N],ans=1,id[N],cnt;
long long xx[N],yy[N],tn[N],td[N];
bool o[N],used[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int main()
{
	read(n);
	F(i,0,n)read(l[i].p0.z,l[i].p0.x,l[i].p0.y,l[i].p1.z,l[i].p1.x,l[i].p1.y),f[i]=i;
	F(i,0,n)F(j,0,i)if(parallel(l[i],l[j]))f[find(i)]=find(j);
	F(i,0,n)find(i);
	F(i,0,n)
	{
		int tmp=1;
		cnt=0;
		F(j,i+1,n)
		{
			if(on_same_plane(l[i],l[j]))
			{
				pointl A=conv(l[j].p0-l[i].p0);
				pointl B=conv(l[j].p1-l[i].p0);
				xx[j]=A.x*B.z-B.x*A.z;
				yy[j]=A.y*B.z-B.y*A.z;
				if(!(xx[j]||yy[j]))
				{
					A=conv(l[j].p0-l[i].p1);
					B=conv(l[j].p1-l[i].p1);
					xx[j]=A.x*B.z-B.x*A.z;
					yy[j]=A.y*B.z-B.y*A.z;
				}
				long long g=gcd(xx[j],yy[j]);
				xx[j]/=g;yy[j]/=g;
				if(yy[j]<0||(yy[j]==0&&xx[j]<0))xx[j]*=-1,yy[j]*=-1;
				if(f[i]!=f[j])get_intersection(l[i],l[j],tn[j],td[j]);else td[j]=0;
				id[cnt++]=j;
			}
		}
		sort(id,id+cnt,[](int u,int v){return tn[u]!=tn[v]?tn[u]<tn[v]:td[u]<td[v];});
		for(int j=0,k=0;j<cnt;j=k)
		{
			while(k<cnt&&tn[id[j]]==tn[id[k]]&&td[id[j]]==td[id[k]])++k;
			if(td[id[j]])ans=max(ans,k-j+1);
		}
		sort(id,id+cnt,[](int u,int v){return xx[u]!=xx[v]?xx[u]<xx[v]:yy[u]<yy[v];});
		for(int j=0,k=0;j<cnt;j=k)
		{
			while(k<cnt&&xx[id[j]]==xx[id[k]]&&yy[id[j]]==yy[id[k]])++k;
			used[f[i]]=true;
			tmp=1;
			F(p,j,k)tmp+=!used[f[id[p]]],used[f[id[p]]]=true;
			ans=max(ans,tmp);
			F(p,j,k)used[f[id[p]]]=false;
			used[f[i]]=false;
		}
	}
	printf("%d\n",ans);
	return 0;
}