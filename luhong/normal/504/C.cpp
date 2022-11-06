#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[101000],n,num[101000];long long ans=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int mid=n+1>>1;int i,j;
	for(i=1;i<=mid;i++)if(a[i]!=a[n-i+1]){break;}
	if(i==mid+1){ans+=((long long)n*(n+1))/2;printf("%lld",ans);return 0;}
	int ok=0;
	for(j=mid;j>=1;j--)if(a[j]!=a[n-j+1])break;
	for(int k=i;k<=j;k++)num[a[k]]++;
	for(int k=n-j+1;k<=n-i+1;k++)num[a[k]]--;
	for(int k=1;k<=n;k++)if(num[a[k]]!=0){ok=1;break;}
	if(!ok){ans+=2ll*(long long)i*(long long)(n&1?mid-j:(mid-j+1));}
	j=n-i+1;memset(num,0,sizeof(num));
	if(n&1)
	{
		for(int k=1;k<=mid;k++)num[a[k]]++;
		for(int k=mid+1;k<=n;k++)num[a[k]]--;
		ok=0;
		for(int k=1;k<=n;k++)
		{
			if(num[k]==1)
			{
				if(ok==0)ok=1;else if(ok==1){ok=2;break;}
			}
			else if(num[k]!=0){ok=2;break;}
		}
		if(ok==1)ans+=i;
		memset(num,0,sizeof(num));
		for(int k=mid;k<=n;k++)num[a[k]]++;
		for(int k=1;k<mid;k++)num[a[k]]--; 
		ok=0;
		for(int k=1;k<=n;k++)
		{
			if(num[k]==1)
			{
				if(ok==0)ok=1;else if(ok==1){ok=2;break;}
			}
			else if(num[k]!=0){ok=2;break;}
		}
		if(ok==1)ans+=i;
	}
	memset(num,0,sizeof(num));
	for(int k=i;k<=j;k++)num[a[k]]++;
	if(n&1)
	{
		int ok=0;j=i;
		for(int k=1;k<=n;k++)
		{
			if(num[k]&1)
			{
				num[k]--;
				if(ok==0)ok=1;else if(ok==1){ok=2;break;}
			}
		}
		if(ok==1)
		{
			for(;i<mid;i++){num[a[i]]-=2;if(num[a[i]]<0)break;}if(i==mid)i--;
			ans+=(i-j)*(long long)j+(long long)j*(long long)j;
		}
		ok=0;memset(num,0,sizeof(num));
		for(int k=j;k<=n-j+1;k++)num[a[k]]++;j=n-j+1;i=j;
		for(int k=1;k<=n;k++)
		{
			if(num[k]&1)
			{
				num[k]--;if(ok==0)ok=1;
				else if(ok==1){ok=2;break;}
			}
		}
		if(ok==1)
		{
			for(;i>mid;i--){num[a[i]]-=2;if(num[a[i]]<0)break;}if(i==mid)i++;
			ans+=(j-i)*(long long)(n-j+1);
		}
	} 
	else
	{
		int ok=0;j=i;
		for(int k=1;k<=n;k++)if(num[k]&1){ok=1;break;}
		if(!ok)
		{
			for(;i<=mid;i++){num[a[i]]-=2;if(num[a[i]]<0)break;}if(i==mid+1)i--;
			ans+=(i-j)*(long long)j+(long long)j*(long long)j;
		}
		memset(num,0,sizeof(num));
		for(int k=j;k<=n-j+1;k++)num[a[k]]++;j=n-j+1;i=j;
		if(!ok)
		{
			for(;i>mid;i--){num[a[i]]-=2;if(num[a[i]]<0)break;}if(i==mid)i++;
			ans+=(j-i)*(long long)(n-j+1);
		}
	}
	printf("%lld",ans);return 0;
} 
// 
//1. i=1,j=mid
//2. i=1,j=n