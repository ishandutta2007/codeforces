#include<cstdio>
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
int n,k,t,ans;
int main()
{
	read(n);read(k);
	F(i,0,n)F(j,i+1,n)
	{
		t=0;
		for(int u=i,v=j;u!=v;u/=k,v/=k)++t;
		if(t>ans)ans=t;
	}
	printf("%d\n",ans);
	F(i,0,n)F(j,i+1,n)
	{
		t=0;
		for(int u=i,v=j;u!=v;u/=k,v/=k)++t;
		printf("%d ",t);
	}
	puts("");
	return 0;
}