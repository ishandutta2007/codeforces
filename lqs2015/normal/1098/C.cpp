#include<bits/stdc++.h>
using namespace std;
long long n,s,sum,cur,lst,dep,ans,num[222222],cnt,ceng,st;
long long lb(long long num,long long i,long long res,long long ans)
{
	if (ans==1)
	{
		return (i+1+i+res)*res/2;
	}
	long long lst=res,cur=num*ans,ret=0,dep=i+1;
	while(1)
	{
		if (lst<cur)
		{
			ret+=lst*dep;
			break;
		}
		ret+=cur*dep;
		dep++;
		lst-=cur;
		cur*=ans;
	}
	return ret;
}
int main()
{
	cin>>n>>s;
	if (s>n*(n+1)/2 || s<1+2*(n-1)) 
	{
		printf("No\n");
		return 0;
	}
	for (long long i=1;i<=n;i++)
	{
		if (lb(1,1,n-1,i)+1<=s)
		{
			ans=i;
			break;
		}
	}
	num[1]=1;cnt=1;lst=s-1;
	for (long long i=2;;i++)
	{
		long long j;
		for (j=1;j<=num[i-1]*ans && j<=n-cnt;j++)
		{
			if (lst>=j*i+lb(j,i,n-cnt-j,ans)) 
			{
				num[i]=j;
				break;
			} 
		}
		cnt+=num[i];
		lst-=i*num[i];
		if (cnt>=n) 
		{
			ceng=i;
			break;
		}
	}
	printf("Yes\n");
	lst=1;cur=2;
	for (long long i=2;i<=ceng;i++)
	{
		st=cur;cnt=0;
		for (long long j=1;j<=num[i];j++)
		{
			cnt++;cur++;
			if (cnt>ans) 
			{
				lst++;
				cnt=1;
			}
			printf("%lld ",lst);
		}
		lst=st;
	}
	return 0;
}