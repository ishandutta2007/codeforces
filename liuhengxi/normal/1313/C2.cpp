#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
typedef long long ll;
const int N=5e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N],b[N],sta[N],top;
ll now,l[N],r[N],ans;
int main()
{
	read(n);
	F(i,0,n)read(b[i]);
	F(i,0,n)a[i]=b[i];
	F(i,0,n)
	{
		if(top)
		{
			bool p=false;
			while(top&&a[sta[top-1]]>=a[i])
			{
				ll tmp=--top?a[sta[top]]-a[sta[top-1]]:a[sta[top]];
				now-=(i-sta[top])*tmp;
				p=true;
			}
			if(top)
			{
				if(p)
				{
					now+=(a[i]-a[sta[top-1]])*ll(i-sta[top])+a[i];
					a[sta[top++]]=a[i];
				}
				else sta[top++]=i,now+=a[i];
			}
			else now=a[sta[top++]=i]*(i+1ll);
		}
		else now=a[sta[top++]=i];
		l[i]=now;
	}
	top=0;
	F(i,0,n)a[i]=b[n-1-i];
	F(i,0,n)
	{
		if(top)
		{
			bool p=false;
			while(top&&a[sta[top-1]]>=a[i])
			{
				ll tmp=--top?a[sta[top]]-a[sta[top-1]]:a[sta[top]];
				now-=(i-sta[top])*tmp;
				p=true;
			}
			if(top)
			{
				if(p)
				{
					now+=(a[i]-a[sta[top-1]])*ll(i-sta[top])+a[i];
					a[sta[top++]]=a[i];
				}
				else sta[top++]=i,now+=a[i];
			}
			else now=a[sta[top++]=i]*(i+1ll);
		}
		else now=a[sta[top++]=i];
		r[n-1-i]=now;
	}
	F(i,0,n)a[i]=b[i];
	F(i,0,n)if(l[i]+r[i]-a[i]>ans)ans=l[i]+r[i]-a[i];
	F(i,0,n)if(l[i]+r[i]-a[i]==ans)
	{
		for(int j=i-1;~j;--j)if(a[j]>a[j+1])a[j]=a[j+1];
		F(j,i+1,n)if(a[j]>a[j-1])a[j]=a[j-1];
		ans=-1;
	}
	F(i,0,n)printf("%d ",a[i]);
	printf("\n");
	return 0;
}