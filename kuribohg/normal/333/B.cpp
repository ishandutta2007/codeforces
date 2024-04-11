#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=1010;
int n,k,x,y,usedx[MAXN],usedy[MAXN],ans;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&x,&y);
		usedx[x]=true;
		usedy[y]=true;
	}
	for(int i=2;i<=(n>>1);i++)
	{
		if(!usedx[i]) ans++;
		if(!usedx[n+1-i]) ans++;
		if(!usedy[i]) ans++;
		if(!usedy[n+1-i]) ans++;
	}
	if((n&1)&&(!usedx[(n+1)>>1]||!usedy[(n+1)>>1])) ans++;
	printf("%d\n",ans);
	return 0;
}