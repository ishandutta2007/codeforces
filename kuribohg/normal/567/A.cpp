#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXN=200010;
const int INF=2147483647;
int n,a[MAXN],Min[MAXN],Max[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		Min[i]=INF;
		Max[i]=max(abs(a[i]-a[1]),abs(a[i]-a[n]));
		if(i-1>0) Min[i]=min(Min[i],a[i]-a[i-1]);
		if(i+1<=n) Min[i]=min(Min[i],a[i+1]-a[i]);
	}
	for(int i=1;i<=n;i++) printf("%d %d\n",Min[i],Max[i]);
	return 0;
}