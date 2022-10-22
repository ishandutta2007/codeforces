#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=505,LogN=10;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int n,m,logn,logm,q,r[N][N],g[N][N],y[N][N],b[N][N],v[N][N],lg[N],st[N][N][LogN][LogN];
char s[N][N];
inline int query(int xl,int xr,int yl,int yr)
{
	int xk=lg[xr-xl],yk=lg[yr-yl];
	return max(max(st[xl][yl][xk][yk],st[xl][yr-(1<<yk)][xk][yk]),
	max(st[xr-(1<<xk)][yl][xk][yk],st[xr-(1<<xk)][yr-(1<<yk)][xk][yk]));
}
int main()
{
	read(n,m,q);
	F(i,1,max(n,m)+1)lg[i]=lg[i-1]+1,(1<<lg[i])>i&&--lg[i];
	logn=lg[n],logm=lg[m];
	F(i,0,n)scanf("%s",s[i]);
	F(i,0,n)F(j,0,m)if(s[i][j]=='R')
	{
		if(i&&j)r[i][j]=min(r[i-1][j-1],min(r[i-1][j],r[i][j-1]))+1;
		else r[i][j]=1;
	}
	F(i,0,n)for(int j=m;~--j;)if(s[i][j]=='G')
	{
		if(i)g[i][j]=min(g[i-1][j+1],min(g[i-1][j],g[i][j+1]))+1;
		else g[i][j]=1;
	}
	for(int i=n;~--i;)F(j,0,m)if(s[i][j]=='Y')
	{
		if(j)y[i][j]=min(y[i+1][j-1],min(y[i+1][j],y[i][j-1]))+1;
		else y[i][j]=1;
	}
	for(int i=n;~--i;)for(int j=m;~--j;)if(s[i][j]=='B')
		b[i][j]=min(b[i+1][j+1],min(b[i+1][j],b[i][j+1]))+1;
	F(i,0,n)F(j,0,m)st[i][j][0][0]=v[i][j]=min(min(r[i][j],g[i][j+1]),min(y[i+1][j],b[i+1][j+1]));
	F(k,0,logn)F(i,0,n+1-(2<<k))F(j,0,m)st[i][j][k+1][0]=max(st[i][j][k][0],st[i+(1<<k)][j][k][0]);
	F(l,0,logn+1)F(k,0,logm)F(i,0,n+1-(1<<l))F(j,0,m+1-(2<<k))st[i][j][l][k+1]=max(st[i][j][l][k],st[i][j+(1<<k)][l][k]);
	while(q--)
	{
		int xl,yl,xr,yr,l=0,R,mid;
		read(xl,yl,xr,yr);
		--xl,--yl,--xr,--yr;
		R=min((xr-xl+1)>>1,(yr-yl+1)>>1)+1;
		while(R-l>1)
		{
			mid=(l+R)>>1;
			if(query(xl+mid-1,xr-mid+1,yl+mid-1,yr-mid+1)>=mid)l=mid;
			else R=mid;
		}
		printf("%d\n",4*l*l);
	}
	return 0;
}