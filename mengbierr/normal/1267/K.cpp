#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
int num[20];
ll n,len;
ll c[25][25];
void cal(ll t)
{
	int i=2;
	while(t)
	{
		num[t%i]++;
		//cerr<<t%i<<" ";
		t/=i;
		len++;
		i++;
	}
	//cerr<<endl<<len<<endl;
}
int main()
{
	c[0][0]=1;
	for(int i=1;i<=25;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
		c[i][j]=c[i-1][j]+c[i-1][j-1];
	}
	int T;scanf("%d",&T);
	while(T--)
	{
		memset(num,0,sizeof(num));len=0;
		scanf("%lld",&n);
		cal(n);
		ll ans1=1,ans2=1;
		ll sum=0;
		for(int i=len;i>=1;i--)
		{
			if(num[i])
			{
				ans1*=c[len-sum-i+1][num[i]];
				sum+=num[i];
			}
		}
		sum=0;
		if(num[0])
		{
			num[0]--;
			for(int i=len;i>=1;i--)
			{
				
				if(num[i]>len-sum-i)ans2=0;
				if(num[i])
				ans2*=c[len-sum-i][num[i]];
				sum+=num[i];
			}
		}else ans2=0;
		//cerr<<ans1<<" "<<ans2<<endl;
		printf("%lld\n",ans1-ans2-1);
	}
	return 0;
}