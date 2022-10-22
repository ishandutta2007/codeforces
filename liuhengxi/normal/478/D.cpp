#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=401000,MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int a,b,n,m,f[N],ans;
int main()
{
	read(a);read(b);n=a+b;
	while(m*(m+1)/2<n)++m;
	f[0]=1;
	F(i,1,m+1)
	{
		int t=i*(i+1)/2,tmp=0;
		for(int j=t;j>=i;--j)(f[j]+=f[j-i])%=MOD;
		F(j,t-b>0?t-b:0,(a<t?a:t)+1)(tmp+=f[j])%=MOD;
		if(tmp)ans=tmp;else break;
	}
	printf("%d\n",ans);
	return 0;
}