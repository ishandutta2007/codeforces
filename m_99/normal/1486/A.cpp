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
		
		int n;
		scanf("%d",&n);
		
		vector<long long> h(n);
		rep(i,n){
			scanf("%lld",&h[i]);
		}
		
		bool ok = true;
		rep(i,n){
			long long t;
			if(i==0)t = 0;
			else t = h[i-1] + 1;
			if(h[i]<t){
				ok=false;
				break;
			}
			long long x  =t;
			t = h[i] - t;
			h[i] = x;
			if(i!=n-1){
				h[i+1] += t;
			}
		}
		
		if(ok){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
		
		
		
		
		
	}
	
	
    return 0;
}