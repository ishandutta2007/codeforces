#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1005,LogN=11;
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
int n,m,ln,lm,a[N][N],s[N][N][LogN][LogN],lg2[N],q;
inline int query(int l1,int r1,int l2,int r2)
{
	int k1=lg2[r1-l1],k2=lg2[r2-l2];
	return max({s[l1][l2][k1][k2],s[l1][r2-(1<<k2)][k1][k2],s[r1-(1<<k1)][l2][k1][k2],s[r1-(1<<k1)][r2-(1<<k2)][k1][k2]});
}
int main()
{
	F(i,0,N)while((2<<lg2[i])<=i)++lg2[i];
	read(n,m);
	ln=lg2[n];lm=lg2[m];
	F(i,0,n)F(j,0,m)read(a[i][j]);
	for(int i=n;~--i;)for(int j=m;~--j;)
		a[i][j]&&(a[i][j]+=min({a[i+1][j],a[i][j+1],a[i+1][j+1]}));
	F(i,0,n)F(j,0,m)s[i][j][0][0]=a[i][j];
	F(k,0,lm)F(i,0,n)for(int h=1<<k,j=m-(h<<1);~j;--j)s[i][j][0][k+1]=max(s[i][j][0][k],s[i][j+h][0][k]);
	F(p,0,ln)F(k,0,lm+1)for(int h=1<<p,i=n-(h<<1);~i;--i)for(int j=m-(1<<k);~j;--j)
		s[i][j][p+1][k]=max(s[i][j][p][k],s[i+h][j][p][k]);
	read(q);
	while(q--)
	{
		int x1,y1,x2,y2;read(x1,y1,x2,y2);--x1,--y1;
		int l=0,r=min(x2-x1,y2-y1)+1,mid;
		while(r-l>1)
		{
			mid=(l+r)>>1;
			if(query(x1,x2-mid+1,y1,y2-mid+1)>=mid)l=mid;
			else r=mid;
		}
		printf("%d\n",l);
	}
	return 0;
}