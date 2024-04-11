#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	//_t = 1;
	rep(_,_t){
		
		long long n,m;
		cin>>n>>m;
		n /= m;
		vector<long long> X(2520,0);
		long long S = 0;
		rep(i,2520){
			long long t = i+1;
			t %= 10;
			t *= m;
			t %= 10;
			X[i] = t;
			S += t;
		}
		
		long long ans = 0LL;
		ans = n/2520;
		ans *= S;
		n %= 2520;
		rep(i,n)ans += X[i];
		
		cout<<ans<<endl;
		
		
	}
	
	return 0;
}