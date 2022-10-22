#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000



int main(){
    
	long long n;
	cin>>n;
	
	map<int,long long> mp[2];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			char c;
			cin>>c;
			if(c=='C'){
				mp[0][i]++;
				mp[1][j]++;
			}
		}
	}
	
	long long ans = 0;
	
	for(int i=0;i<2;i++){
		for(auto a:mp[i]){
			ans += (a.second * (a.second-1)) / 2;
		}
	}
	
	cout<<ans<<endl;
    
    return 0;
}