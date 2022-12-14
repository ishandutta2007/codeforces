#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long sz=1<<17;
long long n,v[111111],t[111111],tree[277777],pan[111111],a[111111],p;
void update(long long beg,long long en,long long l,long long r,long long node)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en)
	{
		tree[node]++;
		return;
	}
	long long mid=(l+r)/2;
	update(beg,en,l,mid,node*2);
	update(beg,en,mid+1,r,node*2+1);
}
long long query(long long x)
{
	long long pos=sz-1+x,res=0;
	while(pos)
	{
		res+=tree[pos];
		pos/=2;
	}
	return res;
}
int main()
{
	scanf("%I64d",&n);
	for (long long i=1;i<=n;i++) scanf("%I64d",&v[i]);
	for (long long i=1;i<=n;i++) 
	{
		scanf("%I64d",&t[i]);
		pan[i]=pan[i-1]+t[i];
	}
	for (long long i=1;i<=n;i++)
	{
		p=lower_bound(pan+1,pan+n+1,pan[i-1]+v[i])-pan-1;
		if (p<=i-2) continue;
		if (p>=n)
		{
			update(i,n,1,sz,1);
			continue;
		}
		update(i,p,1,sz,1);
		a[p+1]+=(v[i]+pan[i-1]-pan[p]);
	}
	for (long long i=1;i<=n;i++)
	{
		printf("%I64d ",query(i)*t[i]+a[i]);
	}
	printf("\n");
	return 0;
}