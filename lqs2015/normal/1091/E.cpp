#include<bits/stdc++.h>
using namespace std;
long long n,a[2222222],pre[2222222],suf[2222222],pos,cur,b[2222222],sum,su[2222222],suu[2222222],llb,rrb; 
long long cf[2222222],lb,rb;
bool f;
int main()
{
//	freopen("1.txt","r",stdin);
	scanf("%I64d",&n);
	for (long long i=1;i<=n;i++) scanf("%I64d",&a[i]);
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for (long long i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	pos=n;
	for (long long i=1;i<=n;i++) b[i]=a[i];
	for (long long i=n;i>=1;i--) suf[i]=suf[i+1]+a[i]; 
	for (long long i=1;i<n;i++)
	{
		sum=suf[i+1];
		while(pos>=1 && a[pos]<i) pos--;
		if (pos<=i) 
		{
			su[i]=sum;
			continue;
		}
		sum=sum-(pre[pos]-pre[i])+(pos-i)*i;
		su[i]=sum;
	}
	pos=n;
	for (long long i=1;i<=n;i++)
	{
		sum=suf[i];
		while(pos>=1 && a[pos]<i) pos--;
		if (pos<=i) 
		{
			suu[i]=sum;
			continue;
		}
		sum=sum-(pre[pos]-pre[i-1])+(pos-i+1)*i;
		suu[i]=sum;
	}
	for (long long k=1;k<=n+1;k++)
	{
		rb=k*(k-1)+suu[k]-pre[k-1];
		if (k<=n) 
		{
			lb=a[k];
		}
		else
		{
			lb=0;
		}
		llb=n+1;rrb=n;
		if (k<=n)
		{
			if (k>=pre[k]-k*(k-1)-su[k])
			{
				llb=pre[k]-k*(k-1)-su[k];rrb=a[k];
			}
		}
		if (lb>llb)
		{
			swap(lb,llb);
			swap(rb,rrb);
		}
		if (llb<=rb) 
		{
			long long mr=max(rrb,rb);
			if (lb<=mr)
			{
				if (lb>=0) 
				{
					if (lb<=n) cf[lb]++;
				}
				else cf[0]++;
				if (mr<=n) cf[mr+1]--;
			}
		} 
		else 
		{
			if (lb<=rb)
			{
				if (lb>=0) 
				{
					if (lb<=n) cf[lb]++;
				}
				else cf[0]++;
				if (rb<=n) cf[rb+1]--;
			}
			if (llb<=rrb)
			{
				if (llb>=0) 
				{
					if (llb<=n) cf[llb]++;
				}
				else cf[0]++;
				if (rrb<=n) cf[rrb+1]--;
			}
		}
	}
	for (long long i=1;i<=n;i++) cf[i]+=cf[i-1];
	for (long long i=0;i<=n;i++) 
	{
		if (cf[i]>=n+1)
		{
			if ((pre[n]&1ll)==(i&1ll)) 
			{
				printf("%I64d ",i);
				f=1;
			}
		}
	}
	if (!f) printf("-1\n");
	else printf("\n");
	return 0;
}