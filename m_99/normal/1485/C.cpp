#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long a,b;
		scanf("%lld %lld",&a,&b);
		long long ans = 0LL;
		for(long long i=2;(i<=b);){
			if(a>=i*i){
				ans += i-1;
				i++;
			}
			else{
				
				long long t = a/(i+1);
				long long ok = i,ng = b+1;
				while(ng-ok>1){
					long long mid = (ok+ng)/2;
					if(a/(mid+1)==t)ok = mid;
					else ng = mid;
				}
				ans += t * (ok-i+1);
				i = ok+1;
			}
			//cout<<ans<<endl;
		}
		printf("%lld\n",ans);
	}
		
	
	return 0;
}