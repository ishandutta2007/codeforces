#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2010;
int n,x,xx,type[MAXN],h[MAXN],m[MAXN],ans,con,last;
bool used[MAXN];
int main()
{
	scanf("%d%d",&n,&x),xx=x;
	for(int i=1;i<=n;i++) scanf("%d%d%d",&type[i],&h[i],&m[i]);
	last=0;
	for(int i=1;i<=n;i++)
	{
		int sub=0;
		for(int j=1;j<=n;j++)
			if(!used[j]&&h[j]<=x&&m[j]>=m[sub]&&type[j]==(last^1)) sub=j;
		if(sub==0) break;
		x+=m[sub];
		used[sub]=true;
		ans++;
		last^=1;
	}
	memset(used,false,sizeof(used));
	x=xx;
	last=1;
	for(int i=1;i<=n;i++)
	{
		int sub=0;
		for(int j=1;j<=n;j++) if(!used[j]&&h[j]<=x&&m[j]>=m[sub]&&type[j]==(last^1)) sub=j;
		if(sub==0) break;
		x+=m[sub];
		used[sub]=true;
		con++;
		last^=1;
	}
	printf("%d\n",max(con,ans));
	return 0;
}