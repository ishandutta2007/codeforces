#include<bits/stdc++.h>
using namespace std;
const int N=2000;
string s;
int slen,p;
int vis[N+5];
int bucket[N+5],check[N+5];
int main()
{
	memset(bucket,-1,sizeof(bucket));
	cin>>slen>>p;
	cin>>s;
	for(int i=0;i<slen;i++)
	{
		if(s[i]=='.') vis[i+1]=-1;
		else vis[i+1]=s[i]-'0';
	}
	bool flag=0;
	for(int i=slen;i>=p+1;i--)
	{
		if(vis[i]==-1&&vis[i-p]==-1) vis[i]=0,vis[i-p]=1,flag=1;
		else if(vis[i]==-1&&vis[i-p]!=-1) vis[i]=vis[i-p]^1,flag=1;
		else if(vis[i]!=-1&&vis[i-p]==-1) vis[i-p]=vis[i]^1,flag=1;
		else if(vis[i]!=vis[i-p]) flag=1;
	}
	for(int i=1;i<=slen;i++) if(vis[i]==-1) vis[i]=0;
	if(!flag) printf("No\n");
	else 
	{
		for(int i=1;i<=slen;i++) printf("%d",vis[i]);
		printf("\n");
	}
	return 0;
}