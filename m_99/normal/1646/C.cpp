#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000003


int main(){
	
	vector<long long> t;

	{
		long long c = 2LL;
		for(int i=3;i<=14;i++){
			c *= i;
			t.push_back(c);
		}
	}
	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long n;
		cin>>n;
		int ans = 100;
		rep(i,1<<t.size()){
			long long cur = 0LL;
			rep(j,t.size()){
				if((i>>j)&1)cur += t[j];
			}
			if(cur > n)continue;
			ans = min(ans,__builtin_popcount(i) + __builtin_popcountll(n-cur));
		}
		cout<<ans<<endl;
		
	}
	
	return 0;
}