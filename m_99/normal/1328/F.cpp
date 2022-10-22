#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 1000000000000000000


int main() {

	int n,k;
	cin>>n>>k;
	
	map<long long,long long> mp;
	
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		mp[a]++;
	}
	
	long long s1=0,s2=0,c1=0,c2=n;
	
	for(auto a:mp){
		s2 += a.first*a.second;
	}
	
	long long ans = Inf;
	
	for(auto a:mp){
		s2 -= a.first*a.second;
		c2 -= a.second;
		
		long long x1 = (a.first-1)*c1 - s1;
		long long x2 = s2 - (a.first+1)*c2;
		
		long long K = k-a.second;
		if(K<=0){
			ans = 0;
			break;
		}
		if(K<=c1){
			ans = min(ans,x1+K);
		}
		if(K<=c2){
			ans = min(ans,x2+K);
		}
		ans = min(ans,x1+x2+K);
		
		s1 += a.first*a.second;
		c1 += a.second;
	}
	
	cout<<ans<<endl;
	
    return 0;
}