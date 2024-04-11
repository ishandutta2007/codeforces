#include<bits/stdc++.h>
#define auto const register int
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=1000000+5;
int arr[MaxN];
int main()
{
	ios::sync_with_stdio(false),cin.tie(NULL);
	register int T;
	cin>>T;
	register int n;
	while(T--)
	{
		cin>>n>>arr[1];
		rep(i,2,n)
			cin>>arr[i],arr[1]&=arr[i];
		cout<<arr[1]<<'\n';
	}
	return 0;
}