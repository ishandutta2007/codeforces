#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e3+5,MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,x,pos,smaller,bigger;
int pow(long long a,int b)
{
	long long c=1;
	while(b)
	{
		if(b&1)(c*=a)%=MOD;
		(a*=a)%=MOD;
		b>>=1;
	}
	return c;
}
int inv(int a)
{
	return pow(a,MOD-2);
}
int A(int n,int m)
{
	long long ans=1;
	if(m>n)return 0;
	F(i,0,m)(ans*=n-i)%=MOD;
	return ans;
}
int main()
{
	int left=0,right=0,ans=0;
	read(n);read(x);read(pos);
	--x;
	right=n;
	while(left<right)
	{
		int middle=(left+right)/2;
		if(middle<=pos)
		{
			left=middle+1;
			++smaller;
		}
		else
		{
			right=middle;
			++bigger;
		}
	}
	--smaller;
	ans=(long long)A(x,smaller)*A(n-1-x,bigger)%MOD;
	ans=(long long)ans*A(n-1-smaller-bigger,n-1-smaller-bigger)%MOD;
	printf("%d\n",ans);
	return 0;
}