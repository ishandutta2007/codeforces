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
int T,n,a[N],c[N];
int main()
{
	read(T);
	while(T--)
	{
		int ans,maxc=0,cnt=0;
		read(n);F(i,0,n)read(a[i]);
		F(i,0,n)c[i]=0;
		F(i,0,n)++c[--a[i]];
		F(i,0,n)if(c[i]>maxc)maxc=c[i];
		F(i,0,n)if(c[i]==maxc)++cnt;
		ans=(n-cnt)/(maxc-1);
		printf("%d\n",ans-1);
	}
	return 0;
}