#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001

int main(){
	
	int n,k;
	scanf("%d %d",&n,&k);
	
	vector<long long> a(n);
	rep(i,n){
		scanf("%lld",&a[i]);
	}
	
	long long ok = 0LL,ng = Inf;
	
	while(ng-ok>1LL){
		long long mid = (ok+ng)/2;
		
		vector<long long> sum(n+1,0LL);
		long long cur = 0LL;
		long long mini = (long long)Inf*Inf;
		bool f = false;
		rep(i,n){
			if(a[i]>=mid)cur++;
			else cur--;
			sum[i+1] = cur;
			if((i+1)-k >= 0){
				mini = min(mini,sum[i+1-k]);
			}
			if(cur-mini>=1){
				f=true;
				break;
			}
		}
		
		if(f)ok = mid;
		else ng = mid;
	}
	
	printf("%lld\n",ok);
	
	
    return 0;
}