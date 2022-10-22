#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000

long long get3(long long n){
	long long ret = n;
	ret *= n-1;
	ret *= n-2;
	ret /= 6;
	return ret;
}

int main(){
	
	int _t;
	cin>>_t;
	
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		
		vector<int> a(n,0);
		rep(i,n){
			int x;
			scanf("%d",&x);
			a[x-1]++;
		}
		
		long long ans = 0LL;
		
		rep(i,n)ans += get3(a[i]);
		rep(i,n-1){
			ans += get3(a[i]+a[i+1]);
			ans -= get3(a[i]);
			ans -= get3(a[i+1]);
		}
		rep(i,n-2){
			ans += get3(a[i]+a[i+1]+a[i+2]);
			ans += get3(a[i]);
			ans += get3(a[i+1]);
			ans += get3(a[i+2]);
			ans -= get3(a[i]+a[i+1]);
			ans -= get3(a[i+1]+a[i+2]);
			ans -= get3(a[i]+a[i+2]);
			
			ans += get3(a[i]+a[i+2]);
			ans -= get3(a[i]);
			ans -= get3(a[i+2]);
			
		}
		
		printf("%lld\n",ans);
			
	}
	
	
    return 0;
}