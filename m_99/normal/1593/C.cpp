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
		scanf("%d %d",&n,&k);
		
		vector<long long> x(k);
		rep(i,k)scanf("%lld",&x[i]);
		sort(x.rbegin(),x.rend());
		
		long long ok = 1,ng = k+1;
		while(ng-ok>1LL){
			long long mid = (ok+ng)/2;
			vector<pair<long long,long long>> c(1,make_pair(n,0));
			rep(i,mid){
				if(c.size()==0 || c.back().first!=x[i])c.emplace_back(x[i],1LL);
				else c.back().second++;
			}
			long long pos = 0LL;
			bool f  =true;
			while(c.size()!=1){
				auto p = c.back();
				c.pop_back();
				pos += (c.back().first - p.first) * p.second;
				if(pos < c.back().first){
					c.back().second += p.second;
				}
				else{
					f = false;
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