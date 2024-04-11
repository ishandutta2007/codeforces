#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100;
const int INF=1000000000;
int n,l,r,x,a[MAXN],ans;
int main()
{
	scanf("%d%d%d%d",&n,&l,&r,&x);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int S=0;S<(1<<n);S++)
	{
		int sum=0,Max=-INF,Min=INF,cnt=0;
		for(int i=0;i<n;i++)
			if(S&(1<<i)) Min=min(Min,a[i]),Max=max(Max,a[i]),sum+=a[i],cnt++;
		if(cnt>=2&&sum>=l&&sum<=r&&Max-Min>=x) ans++;
	}
	printf("%d\n",ans);
	return 0;
}