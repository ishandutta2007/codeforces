#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long w,h,n;
		scanf("%lld %lld %lld",&w,&h,&n);
		
		long long x = 1,y = 1;
		while(w%2==0){
			x *= 2;
			w/=2;
		}
		while(h%2==0){
			y *= 2;
			h/=2;
		}
		
		if(x*y>=n)printf("YES\n");
		else printf("NO\n");
		
		
		
		
		
		
		
	}
	
    return 0;
}