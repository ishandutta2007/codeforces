#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000


int main(){
	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m;
		scanf("%d %d",&n,&m);
		vector<long long> a(n);
		rep(i,n){
			scanf("%lld",&a[i]);
		}
		
		long long temp = a[0];
		a.erase(a.begin());
		a.push_back(temp);
		
		vector<long long> sum(n+1,0LL);
		
		rep(i,n){
			sum[i+1] = a[i];
			sum[i+1] += sum[i];
		}
		
		vector<long long> maxi(n+1,0LL);
		rep(i,n){
			maxi[i+1] = sum[i+1];
			maxi[i+1] = max(maxi[i+1],maxi[i]);
		}
		
		vector<long long> ans(m);
		rep(i,m){
			long long x;
			scanf("%lld",&x);
			x -= temp;
			if(x<=0){
				ans[i] = 0;
				continue;
			}
			if(sum.back() > 0){
				long long ok = Inf,ng = 0LL;
				while(ok-ng>1LL){
					long long mid = (ok+ng)/2;
					long long cnt = mid/n;
					long long xx = x;
	
					if(cnt!=0){
						xx -= maxi.back();
						if(xx<=0){
							ok = mid;
							continue;
						}
						xx--;
						if(cnt!=1){
							xx /= cnt-1;
							xx /= sum.back();
							if(xx<=0){
								ok = mid;
								continue;
							}
						}
						
					}
		
					xx = x;
					xx -= maxi[mid%n];
					if(xx <= 0){
						ok = mid;
						continue;
					}
					xx--;
					if(cnt!=0){
						xx /= cnt;
						xx /= sum.back();
						if(xx<=0){
							ok = mid;
							continue;
						}
						
					}
					

					ng =  mid;
					
				}
				if(ok==Inf)ans[i] = -1;
				else ans[i] = ok;
			}
			else{
				if(maxi.back() < x)ans[i] = -1;
				else{
					ans[i] = distance(maxi.begin(),lower_bound(maxi.begin(),maxi.end(),x));
				}
			}
				
			
		}
		
		rep(i,m){
			if(i!=0)printf(" ");
			printf("%lld",ans[i]);
		}
		printf("\n");
				
		
	}
	
    return 0;
}