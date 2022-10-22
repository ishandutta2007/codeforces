#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000



int main(){
	
	long long n,r,ave;
	cin>>n>>r>>ave;
	ave*=n;
	
	vector<pair<long long,long long>> E(n);
	for(int i=0;i<n;i++){
		cin>>E[i].second>>E[i].first;
		ave-=E[i].second;
	}
	
	sort(E.begin(),E.end());
	
	
	long long ans = 0;
	
	for(int i=0;i<n;i++){
		if(ave<=0)break;
		long long k = r-E[i].second;
		long long m = min(ave,k);
		ans += m * E[i].first;
		ave -= m;
	}
	
	cout<<ans<<endl;
	
    return 0;
}