#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000005

int main(){

	int t;
	cin>>t;
	
	rep(_,t){
		long long n;
		cin>>n;
		long long ans = Inf;
		for(long long i=1;i*i<=n;i++){
			long long a = i;
			long long b = (n+i-1)/i;
			ans = min(ans,a+b-2);
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}