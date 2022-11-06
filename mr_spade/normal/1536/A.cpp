#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,mn,mx;
inline void solve()
{
	int x;
	register int i;
	cin>>n;mn=200;mx=-200;
	for(i=1;i<=n;i++)
		cin>>x,mn=min(x,mn),mx=max(x,mx);
	if(mn<0)
		return puts("NO"),void();
	puts("YES");
	cout<<101<<endl;
	for(i=0;i<=100;i++)
		cout<<i<<' ';
	cout<<endl;
	return;
}
signed main()
{
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}