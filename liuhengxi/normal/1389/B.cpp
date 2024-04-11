#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N],k,z,ans,maxp,now;
int main()
{
	int t;read(t);
	while(t--)
	{
		read(n);read(k);read(z);
		F(i,0,n)read(a[i]);
		ans=now=maxp=0;
		F(i,0,k+1)
		{
			int left=(k-i)/2,tmp;
			if(i!=n-1&&a[i]+a[i+1]>maxp)maxp=a[i]+a[i+1];
			now+=a[i];
			if((i&1)!=(k&1))continue;
			if(left>z)continue;
			tmp=now+left*maxp;
			if(tmp>ans)ans=tmp;
		}
		printf("%d\n",ans);
	}
	return 0;
}