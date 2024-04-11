#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000



int main(){
    
	long long n;
	cin>>n;
	
	long long ans = 0;
	for(int i=1;i<=n;i++){
		ans += ((long long)1<<i);
	}
	
	cout<<ans<<endl;
    
    return 0;
}