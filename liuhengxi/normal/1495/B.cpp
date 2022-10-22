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
int n,p[N],l[N],r[N],ans,a[N],b[N];
int main()
{
	read(n);F(i,0,n)read(p[i]),l[i]=r[i]=1;
	F(i,1,n)if(p[i-1]<p[i])l[i]+=l[i-1];
	for(int i=n-2;~i;--i)if(p[i+1]<p[i])r[i]+=r[i+1];
	F(i,0,n-1)if(l[i]<l[i+1])l[i]=1;
	for(int i=n-1;i;--i)if(r[i]<r[i-1])r[i]=1;
	F(i,1,n)
	{
		a[i]=a[i-1];
		if(l[i-1]>a[i])a[i]=l[i-1];
		if(r[i-1]>a[i])a[i]=r[i-1];
	}
	for(int i=n-2;~i;--i)
	{
		b[i]=b[i+1];
		if(l[i+1]>b[i])b[i]=l[i+1];
		if(r[i+1]>b[i])b[i]=r[i+1];
	}
	F(i,0,n)if(b[i]>a[i])a[i]=b[i];
	F(i,0,n)if(l[i]!=1&&r[i]!=1&&l[i]==r[i]&&l[i]%2==1&&a[i]<l[i])++ans;
	printf("%d\n",ans);
	return 0;
}