#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=110;
int n,valid[MAXN];
char str[MAXN][MAXN];
bool used[MAXN],ok;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%s",str[i]);
	memset(valid,-1,sizeof(valid));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(str[i][j]!='E') valid[i]=j;
	ok=true;
	for(int i=0;i<n;i++)
		if(valid[i]==-1) ok=false;
	if(ok)
	{
		for(int i=0;i<n;i++)
			printf("%d %d\n",i+1,valid[i]+1);
		return 0;
	}
	memset(valid,-1,sizeof(valid));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(str[i][j]!='E') valid[j]=i;
	ok=true;
	for(int i=0;i<n;i++)
		if(valid[i]==-1) ok=false;
	if(ok)
	{
		for(int i=0;i<n;i++)
			printf("%d %d\n",valid[i]+1,i+1);
		return 0;
	}
	puts("-1");
	return 0;
}