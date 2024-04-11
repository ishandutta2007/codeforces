#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int K=35;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,n,k,a[K];
int main()
{
	read(t);
	while(t--)
	{
		read(n);
		k=0;
		while((1<<k)-1<n)++k;
		F(i,0,k)a[i]=(1<<i)<n?(1<<i):n,n-=a[i];
		sort(a,a+k);
		printf("%d\n",k-1);
		F(i,1,k)printf("%d ",a[i]-a[i-1]);
		printf("\n");
	}
	return 0;
}