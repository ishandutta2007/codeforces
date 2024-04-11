#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000



int main(){
	
	int n;
	cin>>n;
	
	map<long long,long long> mp;
	
	for(int i=0;i<n;i++){
		long long b;
		scanf("%lld",&b);
		
		mp[i-b] += b;
	}
	
	long long ans = 0;
	
	for(auto a:mp){
		ans = max(ans,a.second);
	}
	
	cout<<ans<<endl;

	return 0;
}