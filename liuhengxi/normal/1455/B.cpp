#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,x;
int main()
{
	read(t);
	while(t--)
	{
		int sb=0,ans=1e9;
		read(x);
		while(sb*(sb+1)/2<x)++sb;
		if(x==sb*(sb+1)/2)printf("%d\n",sb);
		else
		{
			ans=sb+sb*(sb+1)/2-x;
			--sb;
			if(x-sb*(sb+1)/2<=sb-1)ans=min(ans,sb+1);
			if(x-sb*(sb+1)/2<=2*(sb-1))ans=min(ans,sb+2);
			printf("%d\n",ans);
		}
	}
	return 0;
}