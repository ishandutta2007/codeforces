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
		vector<long long> h(n);
		rep(i,n)scanf("%lld",&h[i]);
		sort(h.begin(),h.end());
		long long ans = 1000000000000000000;
		rep(ii,3){
			long long H = h.back() +ii;
			long long ok = 1000000000000000000;
			long long ng = -1;
			while(ok-ng>1LL){
				long long mid = (ok+ng)/2;
				
				long long c1 = mid/2,c2 = mid/2;
				c1 += mid%2;
				bool f = true;
				rep(i,n){
					long long d = H - h[i];
					long long m = min(d/2,c2);
					d -= m*2;
					c2 -= m;
					if(c1 < d){
						f = false;
					}
					else{
						c1 -= d;
					}
					
				}
				if(f)ok = mid;
				else ng = mid;
				
				
			}
			ans = min(ans,ok);
		}
		printf("%lld\n",ans);
		
	}
	
	
	return 0;
}