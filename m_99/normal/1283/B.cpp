#include <bits/stdc++.h>
using namespace std;
#define modulo 100000
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		int n,k;
		cin>>n>>k;
		
		int ans = 0;
		ans += (n/k)*k;
		n %= k;
		ans += min(n,k/2);
		
		cout<<ans<<endl;
		
	}
	
    return 0;
}