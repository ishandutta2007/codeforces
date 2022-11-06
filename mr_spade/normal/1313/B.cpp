#include<bits/stdc++.h>
using namespace std;
int n,x,y;
inline int run(int s,int n)
{
	if(s<2||s>2*n)
		return 0;
	return min(s-1,2*n-s+1);
}
inline void solve()
{
	int ans=0;
	register int i;
	scanf("%d%d%d",&n,&x,&y);
	if(x+y>=2*n-1)
		printf("%d ",n);
	else if(x+y>=n+1)
		printf("%d ",n-(run(x+y+1,n)-(x<n)-(y<n)+(x<n&&y<n)));
	else
		printf("%d ",1);
	printf("%d\n",min(n,x+y-1));
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