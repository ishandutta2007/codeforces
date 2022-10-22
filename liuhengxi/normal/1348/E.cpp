#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=505;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,k,a[N],b[N];
bool c[N]={true},d[N];
long long sa,sb,ans;
int main()
{
	read(n);read(k);
	F(i,0,n)read(a[i]),read(b[i]),sa+=a[i],sb+=b[i];
	F(i,0,n)
	{
		int l=k-b[i]>1?k-b[i]:1,r=a[i]+1<k?a[i]+1:k;
		F(p,0,k)d[p]=c[p];
		F(p,0,k)F(j,l,r)d[p]=d[p]||c[(p-j+k)%k];
		F(p,0,k)c[p]=d[p];
	}
	ans=sa/k+sb/k;
	F(i,1,k)if(c[i])
	{
		long long tmp=(sa-i)/k+(sb+i-k)/k+1;
		if(tmp>ans)ans=tmp;
	}
	printf("%lld\n",ans);
	return 0;
}