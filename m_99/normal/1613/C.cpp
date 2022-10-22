#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		long long h;
		scanf("%lld",&h);
		
		vector<long long> a(n);
		rep(i,n)scanf("%lld",&a[i]);
		
		a.push_back(a.back() + h);
		
		long long ok = h,ng = 0LL;
		while(ok-ng>1LL){
			long long mid = (ok+ng)/2;
			long long sum = 0LL;
			
			rep(i,n){
				sum += min(a[i+1] - a[i],mid);
			}
			if(sum >= h)ok = mid;
			else ng = mid;
		}
		
		printf("%lld\n",ok);
		
	}
	
	
	return 0;
}