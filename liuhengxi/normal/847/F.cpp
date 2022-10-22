#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=110;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,k,m,a,g[N],c[N],d[N],v[N];
int bad(int i)
{
	int now=0,vote=m-a;
	F(j,0,n)
		if(c[j]>c[i])++now;
		else if(c[j]==c[i]&&d[j]<d[i])++now;
	F(j,now+1,n)
	{
		int need=c[i]-v[j]+1;
		if(vote<need)break;
		vote-=need;++now;
	}
	return now<k&&c[i]?1:0;
}
int good(int i)
{
	int now=0;
	F(j,0,n)if(c[j]>=c[i]+m-a)++now;
	return now<k?1:0;
}
int main()
{
	read(n);read(k);read(m);read(a);
	F(i,0,a)read(g[i]),++c[--g[i]],d[g[i]]=i;
	F(i,0,n)v[i]=c[i];
	sort(v,v+n,greater<int>());
	F(i,0,n)
	{
		int ans=3;
		if(m!=a)ans-=bad(i);else ans-=2*bad(i);
		if(m!=a)ans-=good(i);
		printf("%d ",ans);
	}
	printf("\n");
	return 0;
}