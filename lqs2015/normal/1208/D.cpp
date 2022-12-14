#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,sz,ans[222222],l,r,mid;
long long a[222222],bit[888888];
void update(int p,int x)
{
	while(p<=sz)
	{
		bit[p]+=x;
		p+=p&(-p);
	}
}
long long query(int p)
{
	long long res=0;
	while(p>=1)
	{
		res+=bit[p];
		p-=p&(-p);
	}
	return res;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sz=1;
	while(sz<n) sz*=2;
	for (int i=1;i<=n;i++) update(i,i);
	for (int i=n;i>=1;i--) 
	{
		l=1;r=n;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if (query(mid-1)<=a[i]) l=mid+1;
			else r=mid-1;
		}
		ans[i]=r;update(r,-r);
	}
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return Accepted;
}