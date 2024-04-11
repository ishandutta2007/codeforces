#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000



int main(){
	
	int _t;
	cin>>_t;
	
	map<long long,long long> mp;
	
	for(long long i=1;i*i<=4000000000;i++){
		if(i*i%2==0)continue;
		
		long long a = i,b = (i*i-1)/2;
		long long c = a*a-b;
		if(b<=0||c<=0)continue;
		mp[max({a,b,c})]++;
	}
	
	long long cur = 0LL;
	for(auto &a:mp){
		cur += a.second;
		a.second = cur;
	}
	
	rep(_,_t){
		
		long long n;
		scanf("%lld",&n);
		long long ans;
		auto it=  mp.upper_bound(n);
		if(it==mp.begin())ans = 0LL;
		else{
			it--;
			ans = it->second;
		}
		printf("%lld\n",ans);
	}
		
    return 0;
}