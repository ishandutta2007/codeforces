#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define a(i,j) aaa[(i)*m+(j)]
#define b(i,j) bbb[(i)*m+(j)]
using namespace std;
const int N=1e6+5,INF=0x3fffffff;
const int c[8]={0,1,1,2,1,2,2,3};
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
char aaa[N+1],bbb[N+1];
int n,m,f[N][8],s[N],ans=INF;
int main()
{
	read(n);read(m);
	if(n>=4&&m>=4)return puts("-1"),0;
	if(n<2||m<2)return puts("0"),0;
	F(i,0,n)scanf("%s",&a(i,0));
	if(n<m)
	{
		F(i,0,n)F(j,0,m)
		{
			bbb[j*n+i]=a(i,j);
		}
		n^=m^=n^=m;
		F(i,0,n)F(j,0,m)a(i,j)=b(i,j);
	}
	if(m==2)F(i,0,n)s[i]=(a(i,0)=='1')*2+(a(i,1)=='1');
	else F(i,0,n)s[i]=(a(i,0)=='1')*4+(a(i,1)=='1')*2+(a(i,2)=='1');
	F(i,0,1<<m)f[0][i]=c[s[0]^i];
	F(i,1,n)F(j,0,1<<m)
	{
		f[i][j]=INF;
		F(k,0,1<<m)if(m==2?(c[j^k]&1):(c[(j^k)>>1]&c[(j^k)&3]&1))
			if(f[i-1][k]<f[i][j])f[i][j]=f[i-1][k];
		f[i][j]+=c[s[i]^j];
		if(i==n-1)if(f[i][j]<ans)ans=f[i][j];
	}
	printf("%d\n",ans);
	return 0;
}