#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,t,x;
inline void solve()
{
	register int i;
	cin>>n>>x>>t;
	if(1+(t/x)>n)
		cout<<n*(n-1)/2<<endl;
	else
		cout<<(n-(t/x))*(t/x)+(t/x)*(t/x-1)/2<<endl;
}
signed main()
{
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}