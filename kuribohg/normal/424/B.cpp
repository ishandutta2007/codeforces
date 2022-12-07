#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
const int TAR=1000000;
struct Node
{
	int x,y,num;
}a[100010];
bool cmp(const Node &i,const Node &j)
{
	return (i.x*i.x+i.y*i.y)<(j.x*j.x+j.y*j.y);
}
int n,k,ans,sub;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].num);
	sort(a+1,a+n+1,cmp);
	while(k<TAR&&sub<=n) k+=a[++sub].num;
	ans=a[sub].x*a[sub].x+a[sub].y*a[sub].y;
	if(sub==n+1) puts("-1");
	else printf("%.7lf\n",sqrt(ans));
	return 0;
}