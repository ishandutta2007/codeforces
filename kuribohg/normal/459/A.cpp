#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int x[3],y[3];
int main()
{
	for(int i=1;i<=2;i++) scanf("%d%d",&x[i],&y[i]);
	if(!(x[1]==x[2]||y[1]==y[2]||y[1]-y[2]==x[1]-x[2]||y[1]-y[2]==-x[1]+x[2])) {puts("-1");return 0;}
	if(x[1]==x[2]) printf("%d %d %d %d\n",x[1]+y[1]-y[2],y[1],x[2]+y[1]-y[2],y[2]);
	else if(y[1]==y[2]) printf("%d %d %d %d\n",x[1],y[1]+x[1]-x[2],x[2],y[2]+x[1]-x[2]);
	else if(y[1]-y[2]==x[1]-x[2]) printf("%d %d %d %d\n",x[2],y[1],x[1],y[2]);
	else printf("%d %d %d %d\n",x[1],y[2],x[2],y[1]);
	return 0;
}