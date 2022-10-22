#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000



int main(){
	
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		long long c,sum;
		cin>>c>>sum;
		
		vector<long long> k(c,sum/c);
		for(int j=0;j<sum%c;j++)k[j]++;
		long long ans = 0;
		for(int j=0;j<c;j++){
			ans += k[j]*k[j];
		}
		cout<<ans<<endl;
	}
	
	return 0;
	
}