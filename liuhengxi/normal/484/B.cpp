#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,M=1e6+5,M1=1000000;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N],ans,pre[M];
bool b[M];
int main()
{
	read(n);F(i,0,n)read(a[i]),b[a[i]]=true;
	pre[0]=-1;
	for(int i=1;i<=M1;++i)if(b[i])pre[i]=i;else pre[i]=pre[i-1];
	F(i,1,M1)if(b[i])
	{
		F(j,2,M1/i+1)if(pre[i*j-1]>i&&pre[i*j-1]%i>ans)ans=pre[i*j-1]%i;
		if(pre[M1]>i&&pre[M1]%i>ans)ans=pre[M1]%i;
	}
	printf("%d\n",ans);
	return 0;
}