#include<bits/stdc++.h>
using namespace std;
int n,a[2005],d[4]={0,0,0,0};
int main()
{
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++) scanf("%d",&x),d[0]+=(x==1),d[1]=max(d[0],d[1]+(x==2)),d[2]=max(d[1],d[2]+(x==1)),d[3]=max(d[2],d[3]+(x==2));
	return printf("%d\n",d[3]),0;
}