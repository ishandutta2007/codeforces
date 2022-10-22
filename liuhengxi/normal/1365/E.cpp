#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=500;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n;
long long a[N],ans;
int main()
{
	read(n);
	F(i,0,n)read(a[i]);
	if(n==1)ans=a[0];
	else if(n==2)ans=a[0]|a[1];
	else F(i,0,n)F(j,0,n)F(k,0,n)if((a[i]|a[j]|a[k])>ans)ans=a[i]|a[j]|a[k];
	printf("%lld\n",ans);
	return 0;
}