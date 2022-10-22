#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	int n;
	cin>>n;	
		
	vector<pair<long long,long long>> v(n);
	rep(i,n){
		scanf("%lld %lld",&v[i].first,&v[i].second);
	}
	
	sort(v.begin(),v.end());
	
	long long remain = 0LL;
	long long ans = 0LL;
	
	rep(i,n-1){
		remain = max(remain,v[i].second);
		long long d = v[i+1].first - v[i].first;
		if(d<=remain){
			remain -= d;
			continue;
		}
		else{
			ans += d-remain;
			remain = 0;
		}
	}
	
	rep(i,n){
		ans += v[i].second;
	}
	
	cout<<ans<<endl;
	
    return 0;
}