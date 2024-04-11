#include<bits/stdc++.h>
using namespace std;
int n,a[111111],cnt,nt[111111],r,x,num,in[111111],out[111111],lst[111111],tt;
long long ans;
bool flg,cn[111111];
int check(int x)
{
	return (in[x]<out[x]);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) nt[a[i]]++;
	for (int i=1;i<=n;i++)
	{
		if (nt[i]&1) cnt++;
	}
	if (cnt>1) 
	{
		printf("0\n");
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		if (a[i]!=a[n+1-i]) 
		{
			x=i;
			break;
		}
	}
	r=0;
	for (int i=1;i<=n/2;i++)
	{
		if (a[i]!=a[n+1-i]) num++;
	}
	for (int i=1;i<=n/2;i++) lst[i]=2;
	for (int i=1;i<=n;i++)
	{
		while(r<=n && num) 
		{
			r++;
			if (r>n) break;
			num-=check(a[r]);
			in[a[r]]++;
			num+=check(a[r]);
			if (n%2==0 || (r!=(n+1)/2))
			{
				tt=(r<=n/2 ? r : n+1-r);
				lst[tt]--;
				if (lst[tt]==1)
				{
					if (a[r]!=a[n+1-r]) num--;
				} 
				if (lst[tt]==1)
				{
					num-=check(a[n+1-r]);
					out[a[n+1-r]]++;
					num+=check(a[n+1-r]);
				}
				if (lst[tt]==0)
				{
					num-=check(a[r]);
					out[a[r]]--;
					num+=check(a[r]);
				}
			}
		}
		if (r==i-1)
		{
			ans+=(n-i+1);
			r=i;
		}
		else 
		{
			ans+=(n-r+1);
			num-=check(a[i]);
			in[a[i]]--;
			num+=check(a[i]);
			if (n%2==0 || (i!=(n+1)/2))
			{
				tt=(i<=n/2 ? i : n+1-i);
				lst[tt]++;
				if (lst[tt]==2)
				{
					if (a[i]!=a[n+1-i]) num++;
					num-=check(a[n+1-i]);
					out[a[n+1-i]]--;
					num+=check(a[n+1-i]);
				}
				if (lst[tt]==1)
				{
					num-=check(a[i]);
					out[a[i]]++;
					num+=check(a[i]);
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}