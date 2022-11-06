#include<bits/stdc++.h>
using namespace std;
inline bool issqr(int x)
{
	if(x<=0)
		return 0;
	int s=(int)(sqrt(x)+0.5);
	return s*s==x;
}
inline void solve()
{
	int n;
	scanf("%d",&n);
	if((n%2==0&&issqr(n/2))||(n%4==0&&issqr(n/4)))
		puts("YES");
	else
		puts("NO");
}
signed main()
{
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}