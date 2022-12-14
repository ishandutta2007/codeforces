#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,p,cnt1,cnt2,test,num[1111111],lst,num2[1111111];
int arr[1111111],brr[11111111],ans,crr[11111111];
long long cur;
priority_queue<int> pq;
int binpow(int a,int t)
{
	int res=1,p=a;
	for (int i=t;i;i>>=1)
	{
		if (i&1) res=1ll*res*p%mod;
		p=1ll*p*p%mod;
	}
	return res;
}
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&p);
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&arr[i]);
		}
		if (p==1)
		{
			printf("%d\n",(n&1));
			continue;
		}
		ans=0;
		sort(arr+1,arr+n+1);
		reverse(arr+1,arr+n+1);
		cur=0;
		for (int i=1;i<=n;i++)
		{
			if (cur && arr[i-1]-arr[i]>30)
			{
				for (int j=i;j<=n;j++) ans=(ans-binpow(p,arr[j]))%mod;
				break;
			}
			if (i>1 && cur)
			{
				bool flg=0;
				for (int j=arr[i-1];j>arr[i];j--)
				{
					cur*=p;
					if (cur>n) 
					{
						for (int k=i;k<=n;k++) ans=(ans-binpow(p,arr[k]))%mod;
						flg=1;
						break;
					}	
				}
				if (flg) break;
			}
			if (!cur) 
			{
				ans=(ans+binpow(p,arr[i]))%mod;
				cur++;
			}
			else
			{
				ans=(ans-binpow(p,arr[i]))%mod;
				cur--;
			}
		}
		printf("%d\n",(ans+mod)%mod);
	}
	return 0;
}