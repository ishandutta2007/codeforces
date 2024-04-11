#include<bits/stdc++.h>
#define int long long
#define auto const register int
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=1000000+5,Inf=(1LL<<60)-1;
int arr[MaxN];
signed main()
{
	ios::sync_with_stdio(false),cin.tie(NULL);
	register int T;
	cin>>T;
	register int n;
	while(T--)
	{
		cin>>n;
		register int Max=-Inf,Sum=0;
		rep(i,1,n)
		{
			cin>>arr[i];
			Sum=(Sum+arr[i]);
			Max=max(Max,arr[i]);
		}
		cout<<setprecision(15)<<(Max+((long double)(Sum-Max)/(n-1)))<<endl;
	}
	return 0;
}