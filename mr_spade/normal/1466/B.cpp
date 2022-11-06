#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int a[N];
map<int,int> M;
inline void solve()
{
	int lst=-1,ans=0;
	register int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]),M[a[i]]++;
	for(auto it=M.rbegin();it!=M.rend();it++)
		if(lst==it->first+1)
		{
			ans++;lst=it->first;
		}
		else
		{
			if(it->second>1)
				ans+=2,lst=it->first;
			else
				ans++,lst=it->first+1;
		}
	printf("%d\n",ans);
	M.clear();
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