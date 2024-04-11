#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

long long get(long long x){
	long long ret = x * (x+1) / 2;
	return ret;
}

int main(){

	int t;
	cin>>t;
	
	rep(_,t){
		long long x;
		cin>>x;
		
		int ans = 0;
		for(long long i=1;i<=30;i++){
			long long temp = get((1LL<<i)-1);
			if(temp<=x){
				x -= temp;
				ans ++;
			}
		}
		
		cout<<ans<<endl;
	}

	return 0;
}