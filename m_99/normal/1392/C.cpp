#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000000000000

int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		
		int n;
		scanf("%d",&n);

		vector<long long> a(n);
		for(int i=0;i<n;i++)scanf("%lld",&a[i]);
		
		long long ans = 0LL;
		
		for(int i=1;i<n;i++){
			ans += max(0LL,a[i-1]-a[i]);
		}
		
		printf("%lld\n",ans);
		
	}
	
	return 0;
}