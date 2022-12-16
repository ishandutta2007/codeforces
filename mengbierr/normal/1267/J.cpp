#include<bits/stdc++.h>
using namespace std;
int num[2000005];
int tot,a[2000005];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		tot=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			num[x]++;
		}
		int lim=3000000;
		for(int i=1;i<=n;i++)
		{
			if(num[i]) a[++tot]=num[i],lim=min(lim,num[i]);
		}
		lim++;
		//cout<<lim<<endl;
		int ans=1000000000;
		for(int i=1;i<=lim;i++)
		{
			int temp=0;bool ok=1;
			for(int j=1;j<=tot;j++)
			{
				
				if(a[j]%i==0)
				temp+=a[j]/i;
				else
				{
					if(i-(a[j]%i)>a[j]/i+1)
					{
						ok=0;
						break;
					}
					else temp+=a[j]/i+1;
				}
			}
			if(ok) ans=min(ans,temp);
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++)
		num[i]=0;
	}
	return 0;
}