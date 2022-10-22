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
		scanf("%d",&n);
		
		vector<long long> a(n);
		rep(i,n){
			scanf("%lld",&a[i]);
		}
		
		long long m = 0;
		rep(i,n-1)m = max(m,a[i]*a[i+1]);
		
		printf("%lld\n",m);
		
		
		
		
		
		
		
	}
	
	return 0;
}