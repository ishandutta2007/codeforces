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
int n;
bool vis[300005];
int tot,ans=1;
int main()
{
	cin>>n;int x;
	printf("1 ");
	int now=n+1;
	for(int i=1;i<=n;i++)
	{
		x=read();
		vis[x]=1;
		ans++;
		while(vis[now-1])
		{
			ans--;
			now--;
		}
		printf("%d ",ans);
	}
}