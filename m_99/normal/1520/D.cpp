#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		
		map<long long,long long> mp;
		rep(i,n){
			long long a;
			scanf("%lld",&a);
			mp[a-i]++;
		}
		
		long long ans = 0LL;
		for(auto a:mp){
			long long t = a.second;
			t *= a.second-1;
			t /= 2;
			ans += t;
		}
		
		printf("%lld\n",ans);
		
	}
	
    return 0;
}