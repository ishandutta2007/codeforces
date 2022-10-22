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
int n,m,a[N],c[N],p[N],s[N];
void add(int x,int y)
{
	for(++x;x<=n;x+=(x&-x))c[x]=c[x]>y?c[x]:y;
}
int getmax(int x)
{
	int ans=0;
	for(;x;x-=(x&-x))ans=ans>c[x]?ans:c[x];
	return ans;
}
int dp(int a)
{
	int ans=getmax(a+1)+1;
	add(a,ans);
	return ans;
}
int main()
{
	int ans=0;
	read(n);read(m);
	F(i,0,n)
	{
		int l,r;
		read(l);read(r);--l;
		++a[l];--a[r];
	}
	++n;
	F(i,1,m)a[i]+=a[i-1];
	F(i,0,m)p[i]=dp(a[i]);
	F(i,0,n)c[i+1]=0;
	for(int i=m-1;~i;--i)s[i]=dp(a[i]);
	F(i,0,m)if(p[i]+s[i]-1>ans)ans=p[i]+s[i]-1;
	printf("%d\n",ans);
	return 0;
}