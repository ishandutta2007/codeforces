#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,INF=0x3fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,s,l,a[N],b[N],now,q1[N],q1f,q1r=1,q2[N],q2f,q2r=1,f[N];
int main()
{
	read(n);read(s);read(l);
	if(n==1)
	{
		if(l>1)puts("-1");
		else puts("1");
		return 0;
	}
	F(i,0,n)read(a[i]);
	q1[0]=q2[0]=n-1;
	now=n-2;
	for(int i=n-1;~i;--i)
	{
		if(q1[q1f]>i)++q1f;
		if(q2[q2f]>i)++q2f;
		while(a[q1[q1f]]-a[q2[q2f]]<=s&&now>=0)
		{
			while(q1r>q1f&&a[now]>=a[q1[q1r-1]])--q1r;
			while(q2r>q2f&&a[now]<=a[q2[q2r-1]])--q2r;
			q1[q1r++]=now;q2[q2r++]=now;
			--now;
		}
		b[i+1]=now+1;
		if(a[q1[q1f]]-a[q2[q2f]]>s)++b[i+1];
	}
	F(i,1,n+1)f[i]=INF;
	q1f=q1r=0;
	F(i,1,n+1)
	{
		if(i>=l)
		{
			while(q1r>q1f&&f[i-l]<=f[q1[q1r-1]])--q1r;
			q1[q1r++]=i-l;
		}
		while(q1r>q1f&&q1[q1f]<b[i])++q1f;
		if(q1r>q1f)f[i]=f[q1[q1f]]+1;
	}
	printf("%d\n",f[n]>=INF?-1:f[n]);
	return 0;
}