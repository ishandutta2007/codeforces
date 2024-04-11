#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,MOD=1000000007,M=19,P[M]=
{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N],x[M],ans=1;
bool add(int y)
{
	for(int j=M-1;~j;--j)if(y&1<<j)
	{
		if(x[j])y^=x[j];
		else
		{
			x[j]=y;
			return true;
		}
	}
	return false;
}
int main()
{
	read(n);
	F(i,0,n)
	{
		int c;read(c);
		F(j,0,M)while(c%P[j]==0)a[i]^=1<<j,c/=P[j];
	}
	F(i,0,n)if(!add(a[i]))(ans+=ans)%=MOD;
	--ans;
	printf("%d\n",ans);
	return 0;
}