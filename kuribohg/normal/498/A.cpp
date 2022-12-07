#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
typedef long long LL;
int n,ans;
LL x1,y1,x2,y2,a,b,c,t1,t2;
int main()
{
	scanf("%I64d%I64d%I64d%I64d%d",&x1,&y1,&x2,&y2,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d%I64d%I64d",&a,&b,&c);
		t1=a*x1+b*y1+c;
		t2=a*x2+b*y2+c;
		if(t1<0&&t2>0) ans++;
		if(t1>0&&t2<0) ans++;
	}
	printf("%d\n",ans);
	return 0;
}