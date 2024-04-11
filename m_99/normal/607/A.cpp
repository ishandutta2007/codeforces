#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 2000000000000000000



int main(){

	int n;
	cin>>n;
	
	vector<pair<long long,long long>> v(n);
	for(int i=0;i<n;i++){
		scanf("%lld %lld",&v[i].first,&v[i].second);
	}
	
	sort(v.begin(),v.end());
	
	vector<int> dp(n+1,0);

	
	for(int i=0;i<n;i++){
		int d = distance(v.begin(),lower_bound(v.begin(),v.end(),make_pair(v[i].first - v[i].second,1LL)));
		dp[i+1] = 1+dp[d];
	}
	int ans = n;
	for(int i=0;i<=n;i++){
		ans = min(ans,(n-i)+(i-dp[i]));
	}
	
	cout<<ans<<endl;
	
	return 0;
}