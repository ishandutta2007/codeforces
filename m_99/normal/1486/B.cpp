#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		
		vector<long long> x(n),y(n);
		rep(i,n){
			scanf("%lld %lld",&x[i],&y[i]);
		}
		
		sort(x.begin(),x.end());
		sort(y.begin(),y.end());
		
		long long ans = 1LL;
		if(n%2==0){
			long long t = x[n/2] - x[n/2-1];
			ans *= t+1;
			t = y[n/2] - y[n/2-1];
			ans *= t+1;
		}
		printf("%lld\n",ans);
	}
	
	
    return 0;
}