#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long n,k;
		scanf("%lld %lld",&n,&k);
		k--;
		if(n%2==0){
			k %= n;
			printf("%lld\n",1+k);
			continue;
		}
		else{
			
			long long x = k*2 / (n-1);
			k += x;
			k %= n;
			printf("%lld\n",1+k);
		}
	}
		
    return 0;
}