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
		cin>>n;
		
		vector<long long> h(n);
		rep(i,n)scanf("%lld",&h[i]);
		
		long long ok = 0,ng = Inf;
		while(ng-ok>1LL){
			long long mid = (ok+ng)/2;
			vector<long long> hh(n,0);
			
			for(int i=n-1;i>=2;i--){
				if(h[i] + hh[i]<mid)break;
				long long t = (h[i] + hh[i])-mid;
				t/=3;
				t = min(t,h[i]/3);
				hh[i] -= t*3;
				hh[i-1] += t;;
				hh[i-2] += t*2;
			}
			rep(i,n)hh[i] += h[i];
			
			long long m = Inf;
			rep(i,n)m = min(m,hh[i]);
			if(m<mid)ng = mid;
			else ok = mid;
		}
		printf("%lld\n",ok);
	}
	
	return 0;
}