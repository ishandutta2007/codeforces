#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000


int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int N;
		cin>>N;
		int ans = 1;
		N--;
		ans += N/2;
		cout<<ans<<endl;
	}
	
	return 0;
}