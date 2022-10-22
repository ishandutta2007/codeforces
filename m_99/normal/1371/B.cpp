#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000

long long sum(long long n){
	return n*(n+1)/2;
}

int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		long long n,r;
		cin>>n>>r;
		
		long long ans = 0LL;
		if(r>=n)ans++;
		r = min(r,n-1);
		ans += sum(r);
		cout<<ans<<endl;
	}
	
	return 0;
}