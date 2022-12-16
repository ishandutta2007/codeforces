#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f;
}
char s[200005],t[200005];int v[200005];
int main()
{
	scanf("%s%s",s+1,t+1);
	int n=strlen(s+1),m=strlen(t+1);
	for(int i=1;i<=n;i++)
	{
		v[i]=v[i-1]+(s[i]=='1');
	}
	long long ans=0;
	for(int i=1;i<=m;i++)
	{
		int r=min(i,n),l=max(1,n-m+i);
		if(t[i]=='1')
		{
			ans+=(r-l+1-v[r]+v[l-1]);
		}
		else
		{
			ans+=v[r]-v[l-1];
		}
	}
	cout<<ans;
}