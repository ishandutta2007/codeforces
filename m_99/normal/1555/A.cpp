#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000005


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long n;
		scanf("%lld",&n);
		
		if(n%2==1)n++;
		
		n /= 2;
		long long ans = 0LL;
		if(n>=8)ans = n;
		else{
			ans = Inf;
			rep(i,4){
				rep(j,4){
					rep(k,4){
						if(i*3+j*4+k*5>=n)ans = min(ans,(long long)i*3+j*4+k*5);
					}
				}
			}
		}
		cout<<ans*5<<endl;
		
		
	}
	
	return 0;
}