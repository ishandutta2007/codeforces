#include<cstdio>
#include<cstring>
#include<algorithm>
#include<functional>
#define int long long
using std::inplace_merge;
using std::sort;
using std::greater;
const int N=5e5+5;
int n,s,ans1,ans2;
int a[N],d[N],sum[N];
inline bool check(int x,int f)
{
	int pos=n+2;
	register int i;
	memcpy(d+1,a+1,sizeof(int)*n);
	d[n+1]=x;inplace_merge(d+1,d+n+1,d+n+2,greater<int>());
	for(i=1;i<=n+1;i++)
		sum[i]=sum[i-1]+d[i];
	for(i=1;i<=n+1;i++)
	{
		if(pos==i)
			pos++;
		while(pos-1>i&&d[pos-1]<i)
			pos--;
		if(sum[i]>i*(i-1)+(pos-1-i)*i+sum[n+1]-sum[pos-1])
		{
			if(f==0)
				return d[i]<=x;
			else if(f==1)
				return d[i+1]>=x;
			else
				return 0;
		}
	}
	return 1;
}
signed main()
{
	int l,r,mid;
	register int i;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]),s+=(a[i]&1);
	sort(a+1,a+n+1,greater<int>());
	s&=1;
	l=0;r=(n-s)/2+1;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(check(2*mid+s,0))
			r=mid;
		else
			l=mid+1;
	}
	ans1=l;
	l=-1;r=(n-s)/2;
	while(l<r)
	{
		mid=(l+r+1)>>1;
		if(check(2*mid+s,1))
			l=mid;
		else
			r=mid-1;
	}
	ans2=l;
	if(ans1>ans2)
		return puts("-1"),0;
	if(!check(2*ans1+s,2))
		return puts("-1"),0;
	for(i=ans1;i<=ans2;i++)
		printf("%lld ",2*i+s);
	putchar('\n');
	return 0;
}