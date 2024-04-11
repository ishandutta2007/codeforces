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
		
		map<long long,int> mp;
		for(long long i=2;i*i<=n;i++){
			while(n%i==0){
				mp[i] ++;
				n/=i;
			}
		}
		if(n!=1)mp[n]++;
		
		int maxi = 0;
		for(auto a:mp){
			maxi = max(maxi,a.second);
		}
		
		vector<long long> ans(maxi,1LL);
		
		for(auto a:mp){
			rep(i,a.second)ans[i] *= a.first;
		}
		reverse(ans.begin(),ans.end());
		printf("%d\n",ans.size());
		rep(i,ans.size()){
			if(i!=0)printf(" ");
			printf("%lld",ans[i]);
		}
		printf("\n");
		
	}
	
	return 0;
}