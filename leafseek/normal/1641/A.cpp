#include<bits/stdc++.h>
#define int long long
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=1000000+5;
multiset<pair<int,int>> Set;
multiset<pair<int,int>>::iterator It;
bitset<MaxN> Bitset;
int arr[MaxN];
signed main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int T;
	cin>>T;
	int n,m;
	while(T--)
	{
		Set.clear();
		cin>>n>>m;
		rep(i,1,n)
			cin>>arr[i],Bitset[i]=false;
		sort(arr+1,arr+n+1);
		rep(i,1,n)
			Set.insert(make_pair(arr[i],i));
		int cnt=0;
		rep(i,1,n)
		{
			if(Bitset[i]) continue;
			It=Set.lower_bound(make_pair(arr[i]*m,0));
			if(It==Set.end()) continue;
			if(It->first!=arr[i]*m) continue;
			Set.erase(It);
			++cnt,Bitset[It->second]=true;
		}
		cout<<(n-(cnt<<1))<<'\n';
	}
	return 0;
}