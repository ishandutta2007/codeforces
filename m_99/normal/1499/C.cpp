#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000


int main(){
	
	
	int t;
	cin>>t;
	
	rep(_,t){
		
		int n;
		scanf("%d",&n);
		vector<long long> c(n);
		rep(i,n)scanf("%lld",&c[i]);
		
		long long x = n,y = n;
		long long ans = Inf;
		long long cur = 0LL;
		long long min0 = Inf,min1 = Inf;
		rep(i,n){
			cur += c[i];
			if(i%2==0)min0 = min(min0,c[i]);
			else min1 = min(min1,c[i]);
			if(i%2==0)x--;
			else y--;
			if(i!=0){
				ans = min(ans,cur + x*min0 + y*min1);
			}
		}
		printf("%lld\n",ans);
	}
		
	
    return 0;
}