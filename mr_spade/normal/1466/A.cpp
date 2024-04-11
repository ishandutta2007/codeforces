#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n;
int x[N];
set<int> S;
inline void solve()
{
	register int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&x[i]);
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			S.insert(x[j]-x[i]);
	printf("%d\n",(int)S.size());
	S.clear();
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