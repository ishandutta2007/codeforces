#include<bits/stdc++.h>
using namespace std;
int d[100001];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(d,0,sizeof(d));
		int n,x,ans=0;
		cin>>n>>x;
		for(register int i=1;i<=n;i++)
		{
			char a;
			cin>>a;
			if(a=='0')d[i]=d[i-1]+1;
			else d[i]=d[i-1]-1;
		}
		for(register int i=1;i<n;i++)
		{
			if(d[n]!=0)
			{
				if(((x-d[i])/d[n])*d[n]==(x-d[i])&&((x-d[i])/d[n]>=0))ans++;
			}
			else
			{
				if(x==d[i])ans++;
			}
		}
		if(d[n]!=0)
		{
			if((x/d[n])*d[n]==x&&x/d[n]>=0)ans++;
		}
		else if(d[n]==x)ans++;
		if(ans!=0&&d[n]==0)cout<<"-1"<<endl;
		else cout<<ans<<endl;
	}
}