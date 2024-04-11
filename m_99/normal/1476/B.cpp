#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,k;
		scanf("%d %d",&n,&k);
		
		vector<long long> p(n);
		rep(i,n){
			scanf("%lld",&p[i]);
		}
		
		long long ok = 100000000000000,ng = -1LL;
		while(ok-ng>1){
			long long mid = (ok+ng)/2;;
			long long cur = p[0] + mid;
			bool f = true;
			for(int i=1;i<n;i++){
				if(k*cur >= p[i]*100){
					cur += p[i];
				}
				else{
					f=false;
					break;
				}
			}
			if(f)ok = mid;
			else ng = mid;
			
		}
		printf("%lld\n",ok);
		
	}
	
    return 0;
}