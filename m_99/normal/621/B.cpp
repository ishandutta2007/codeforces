#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000



int main(){
	
	int n;
	cin>>n;
	
	map<int,long long> wa,sa;
	
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		
		wa[x+y]++;
		sa[x-y]++;
	}
	
	long long ans = 0;
	
	for(auto a:wa){
		ans += (a.second * (a.second-1))/2;
	}
	
	for(auto a:sa){
		ans += (a.second * (a.second-1))/2;
	}
	
	cout<<ans<<endl;
	
    return 0;
}