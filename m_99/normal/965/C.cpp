#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 1000000000000


int main() {
	
	long long n,k,M,D;
	cin>>n>>k>>M>>D;
	long long ans = 0;
	for(long long i=1;i<=D;i++){
		if(i*k>n)break;
		long long t = n/((i-1)*k+1);
		t = min(t,M);
		if(t>=(n+1+i*k)/(i*k+1))ans = max(ans,i*t);
	}
	
	cout<<ans<<endl;
	
	
	
    return 0;
}