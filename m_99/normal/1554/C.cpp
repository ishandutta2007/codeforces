#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000005


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long n,m;
		scanf("%lld %lld",&n,&m);
		swap(n,m);
		long long ok = -1,ng = Inf;
		while(ng-ok>1){
			long long mid = (ok+ng)/2;
			
			bool f = false;
			long long y = 0LL;
			for(int i=30;i>=0;i--){
				int need = (((m>>i)&1)^1);
				if(f){
					y |= (1<<i) * need;
				}
				else{
					if((mid>>i)&1){
						if(need==0){
							f = true;
						}
						else{
						}
						y |= (1<<i)*need;
					}
					else{
						continue;
					}
				}
				
			}
			/*
			if(mid<=5){
				cout<<mid<<','<<y<<endl;
			}
			*/
			if((y^m)<=n)ok = mid;
			else ng = mid;
			
		}
		
		printf("%lld\n",ok+1);
		
		
		
	}
	
	return 0;
}