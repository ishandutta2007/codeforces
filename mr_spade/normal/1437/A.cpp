#include<cstdio>
inline void solve()
{
	int l,r;
	scanf("%d%d",&l,&r);
	if(l*2>=r+1)
		puts("YES");
	else
		puts("NO");
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