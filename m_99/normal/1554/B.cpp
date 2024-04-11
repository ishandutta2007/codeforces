#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 100000000000000000


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long n,k;
		scanf("%lld %lld",&n,&k);
		
		vector<long long> a(n);
		rep(i,n){
			scanf("%lld",&a[i]);
		}
		
		long long m = -Inf;
		
		rep(i,min(n,(long long)103)){
			rep(j,min(n,(long long)103)){
				if(i<=j)continue;
				m = max(m,(n-i)*(n-j) - k*(a[n-1-i]|a[n-1-j]));
			}
		}
		
		
		printf("%lld\n",m);
		
		
		
		
		
		
		
	}
	
	return 0;
}