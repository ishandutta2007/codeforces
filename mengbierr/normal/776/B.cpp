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
int vis[100005];
int main()
{
	int n=read()+1,maxx=0;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])
		{
			for(int j=i+i;j<=n;j+=i)
			vis[j]=1;
		}
		vis[i]++;
		maxx=max(maxx,vis[i]);
	}
	cout<<maxx<<endl;
	for(int i=2;i<=n;i++)
	printf("%d ",vis[i]);
}