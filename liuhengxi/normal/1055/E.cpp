#include<cstdio>
#include<cstring>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1505,INF=0x3fffffff;
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
bool check(int);
int solve()
{
	int l=0,r=INF,mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid;
	}
	return r==INF?-1:r;
}
int n,s,m,k,a[N],c[N],l[N],r[N],f[N][N],mx[N];
bool check(int v)
{
	int h;
	memset(f,0x3f,sizeof f);
	F(i,0,n)c[i+1]=c[i]+(a[i]<=v);
	h=c[n];
	F(i,0,h+1)mx[i]=i;
	F(i,0,m)if(c[l[i]]<mx[c[r[i]]])mx[c[r[i]]]=min(mx[c[r[i]]],c[l[i]]);
	for(int i=h;i;--i)mx[i-1]=min(mx[i-1],mx[i]);
	F(i,0,s+1)f[0][i]=0;
	for(int i=1;i<=h;++i)
	{
		F(j,0,s+1)f[i][j]=min(f[i][j],f[i-1][j]+1);
		F(j,0,s)f[i][j+1]=min(f[i][j+1],f[mx[i]][j]);
	}
	return h-f[h][s]>=k;
}
int main()
{
	read(n,m,s,k);
	F(i,0,n)read(a[i]);
	F(i,0,m)--read(l[i]),read(r[i]);
	check(2);
	printf("%d\n",solve());
	return 0;
}