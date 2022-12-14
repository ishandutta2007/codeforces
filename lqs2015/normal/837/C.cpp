#include<iostream>
#include<cstdio>
using namespace std;
int n,a,b,ans;
int x[111],y[111];
int main()
{
	cin>>n>>a>>b;
	for (int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			if ((x[i]+x[j]<=a && max(y[i],y[j])<=b) || (x[i]+y[j]<=a && max(x[j],y[i])<=b)
			|| (x[i]+x[j]<=b && max(y[i],y[j])<=a) || (x[i]+y[j]<=b && max(x[j],y[i])<=a)
			|| (max(x[i],x[j])<=a && y[i]+y[j]<=b) || (max(x[i],y[j])<=a && x[j]+y[i]<=b)
			|| (max(x[i],x[j])<=b && y[i]+y[j]<=a) || (max(x[i],y[j])<=b && x[j]+y[i]<=a))
			{
				ans=max(ans,x[i]*y[i]+x[j]*y[j]);
			} 
		}
	}
	cout<<ans<<endl;
	return 0;
}