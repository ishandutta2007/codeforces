#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
int a,b,x[105],y[105],ans;
int main()
{
	int n=read(),a=read(),b=read();
	for(int i=1;i<=n;i++)
	{
		x[i]=read(),y[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(x[i]<=a&&x[j]<=a&&y[i]<=b&&y[j]<=b)
			{
				if(x[i]+x[j]<=a||y[i]+y[j]<=b)
				ans=max(ans,x[i]*y[i]+x[j]*y[j]);
				//else
				//ans=max(ans,x[i]*y[i]+x[j]*y[j]-(x[i]+x[j]-a)*(y[i]+y[j]-b));
			}
			if(x[i]<=a&&x[j]<=b&&y[i]<=b&&y[j]<=a)
			{
				if(x[i]+y[j]<=a||y[i]+x[j]<=b)
				ans=max(ans,x[i]*y[i]+x[j]*y[j]);
			//	else
				//ans=max(ans,x[i]*y[i]+x[j]*y[j]-(x[i]+y[j]-a)*(y[i]+x[j]-b));
			}
			if(x[i]<=b&&x[j]<=a&&y[i]<=a&&y[j]<=b)
			{
				if(x[i]+y[j]<=b||y[i]+x[j]<=a)
				ans=max(ans,x[i]*y[i]+x[j]*y[j]);
				//else
				//ans=ans=max(ans,x[i]*y[i]+x[j]*y[j]-(y[i]+x[j]-a)*(x[i]+y[j]-b));
			}
			if(x[i]<=b&&x[j]<=b&&y[i]<=a&&y[j]<=a)
			{
				if(x[i]+x[j]<=b||y[i]+y[j]<=a)
				ans=max(ans,x[i]*y[i]+x[j]*y[j]);
				//else
				//ans=max(ans,x[i]*y[i]+x[j]*y[j]-(x[i]+x[j]-b)*(y[i]+y[j]-a));
			}
		}
	}
	cout<<ans;
}