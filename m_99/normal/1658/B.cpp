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
		if(n%2==1){
			cout<<0<<endl;
			continue;
		}
		long long ans = 1LL;
		rep(i,n/2){
			ans *= i+1;
			ans %= 998244353;
			ans *= i+1;
			ans %= 998244353;
		}
		cout<<ans<<endl;
		
	}
	
	return 0;
}