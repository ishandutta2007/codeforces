#include<cstdio>
#include<vector>
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
constexpr int N=250;
unsigned long long C[N][N];
void solve(int k,long long n,long long *a)
{
	if(k==0)
	{
		a[0]=n;
		return;
	}
	long long m=k<63?n>>(k-1):0,mm;
	if(m)mm=m<<(k-1);
	else mm=0;
	solve(k-1,n-mm,a);
	if(m)F(i,0,k)a[i]+=m*C[k-1][i];
	a[k]=0;
	for(int i=k;~--i;)
	{
		a[i+1]+=a[i]>>1;
		a[i]-=a[i]>>1;
	}
}
long long a[N],b[N];
int tt;
int main()
{
	F(i,0,N)C[i][0]=1;
	F(i,1,N)F(j,1,i+1)C[i][j]=C[i-1][j]+C[i-1][j-1];
	read(tt);
	while(tt--)
	{
		long long t;
		int x,y;
		read(t,x,y);
		if(x+y>t)puts("NO");
		else
		{
			t-=x+y;
			solve(x+y,t,a);
			solve(x+y,t+1,b);
			puts(a[x]!=b[x]?"YES":"NO");
		}
	}
	return 0;
}