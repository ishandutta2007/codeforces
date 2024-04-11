#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,sum;
int a[N];
inline void solve()
{
	register int i;
	cin>>n;sum=0;
	for(i=1;i<=n;i++)
		cin>>a[i],sum+=a[i];
	if(sum==n)
		puts("0");
	else if(sum<n)
		puts("1");
	else
		cout<<sum-n<<endl;
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