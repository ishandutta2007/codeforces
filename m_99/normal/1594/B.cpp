#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		long long n,k;
		cin>>n>>k;
		
		//k++;
		
		long long ans = 0LL;
		long long cur = 1LL;
		while(k!=0){
			if(k&1){
				ans += cur;
				ans %= 1000000007;
			}
			k/=2;
			cur *= n;
			cur %= 1000000007;
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}