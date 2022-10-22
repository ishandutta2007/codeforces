#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m;
		scanf("%d %d",&n,&m);
		
		vector<long long> k(n),c(m);
		rep(i,n){
			scanf("%lld",&k[i]);
			k[i]--;
		}
		rep(i,m)scanf("%lld",&c[i]);
		
		sort(k.rbegin(),k.rend());
		
		long long ans = 0LL;
		long long cur = 0;
		rep(i,n){
			cur += c[k[i]];
		}
		ans = cur;
		rep(i,min(m,n)){
			cur -= c[k[i]];
			cur += c[i];
			ans = min(ans,cur);
		}
		
		printf("%lld\n",ans);
		
		
		
		
		
	}
	
    return 0;
}