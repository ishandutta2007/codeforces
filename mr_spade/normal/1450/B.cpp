#include<bits/stdc++.h>
#define abs aaa
using namespace std;
inline int abs(int x)
{
	return x<0?-x:x;
}
const int N=1e5+5;
int n,k;
int x[N],y[N];
inline void solve()
{
	register int i,j;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			if(abs(x[i]-x[j])+abs(y[i]-y[j])>k)
				goto end1;
		goto end2;
		end1:;
	}
	end2:;
	puts(i<=n?"1":"-1");
	return;
}
signed main()
{
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}