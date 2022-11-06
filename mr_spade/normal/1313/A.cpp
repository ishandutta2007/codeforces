#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a,b,c;
int cnt[N][3],tt[N],tot[N][3];
inline void solve()
{
	int ans=0;
	register int i;
	scanf("%d%d%d",&a,&b,&c);
	for(i=0;i<(1<<8);i++)
		if(tot[i][0]<=a&&tot[i][1]<=b&&tot[i][2]<=c)
			ans=max(ans,tt[i]);
	printf("%d\n",ans);
	return;
}
signed main()
{
	int T;
	register int i,j,k;
	for(i=0;i<8;i++)
		for(j=0;j<3;j++)
			cnt[i][j]=i>>j&1;
	for(i=0;i<(1<<8);i++)
		for(j=1;j<8;j++)
			if(i>>j&1)
			{
				tt[i]++;
				for(k=0;k<3;k++)
					tot[i][k]+=cnt[j][k];
			}
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}