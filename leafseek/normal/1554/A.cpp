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
		cin>>n;
		rep(i,1,n)
			cin>>arr[i];
		register long long Answer=0;
		rep(i,1,n-1)
			Answer=max(Answer,(long long)max(arr[i],arr[i+1])*min(arr[i],arr[i+1]));
		cout<<Answer<<endl;
	}
	return 0;
}