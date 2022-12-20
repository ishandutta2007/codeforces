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
char s[1005];bool vis[35];
int main()
{

	scanf("%s",s+1);
	int k=read(),n=strlen(s+1);
	if(n<k)
	{
		puts("impossible");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		vis[s[i]-'a']=1;
	}
	int ans=0;
	for(int i=0;i<26;i++)
	{
		if(vis[i])
		ans++;
	}
	if(ans>=k)
	{
		printf("0");
	}
	else
	{
		printf("%d",k-ans);
	}
}