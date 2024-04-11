#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=400000+5,MaxM=400000+5;
int arr[MaxN],lef[MaxM],rig[MaxM];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int T;
	cin>>T;
	int n,m;
	while(T--)
	{
		cin>>n,m=0;
		rep(i,1,n)
			cin>>arr[i],m=max(m,arr[i]);
		rep(i,1,m)
			lef[i]=rig[i]=0;
		rep(i,1,n)
		{
			if(i&1) ++lef[arr[i]];
			else ++rig[arr[i]];
		}
		sort(arr+1,arr+n+1);
		rep(i,1,n)
		{
			if(i&1) --lef[arr[i]];
			else --rig[arr[i]];
		}
		bool Flag=true;
		rep(i,1,m)
			if(lef[i]||rig[i])
				Flag=false;
		if(Flag)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}