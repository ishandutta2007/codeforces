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
int ans=-1;int a[105],b[105];
int main()
{
	int n=read(),s=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();b[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		if((s<a[i])||(s==a[i]&&b[i]!=0)) continue;
		else
		{
			if(b[i]==0)
			ans=max(ans,0);
			else ans=max(ans,100-b[i]);
		}
	}
	cout<<ans;
}