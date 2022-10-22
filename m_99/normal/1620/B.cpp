#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long h,w;
		cin>>w>>h;
		
		long long ans = 0;
		rep(i,4){
			int k;
			scanf("%d",&k);
			vector<long long> x(k);
			rep(j,k)scanf("%d",&x[j]);
			long long t = x.back() - x[0];
			if(i<2)t *= h;
			else t *= w;
			ans = max(ans,t);
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}