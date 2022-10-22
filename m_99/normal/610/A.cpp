#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000



int main(){
	
	long long n;
	cin>>n;
	
	long long ans = 0;
	

	
	if(n%2==0){
		n/=2;
		n--;
		ans += n/2;
	}
	
	cout<<ans<<endl;
	
	
	
	return 0;
}