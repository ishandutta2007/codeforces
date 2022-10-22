#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		
		vector<long long> a(n);
		long long sum = 0LL;
		rep(i,n){
			scanf("%lld",&a[i]);
			sum += a[i];
		}
		
		long long x = sum%n;
		long long y = n-x;
		
		printf("%lld\n",x*y);
		
	}
	
    return 0;
}