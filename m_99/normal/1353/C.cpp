#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long n;
		cin>>n;
		
		long long ans = 0;
		for(long long i=1;i<=n;i+=2){
			ans += (n*n-i*i);
		}
		
		cout<<ans<<endl;
		
	}
	
	return 0;
}