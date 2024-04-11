#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,k;
		cin>>n>>k;
		
		map<int,int> mp;
		rep(i,n){
			int a;
			scanf("%d",&a);
			a %= k;
			a = k-a;
			a %= k;
			if(a!=0)mp[a]++;
		}
		int maxi = 0;
		int t = 0;
		for(auto a:mp){
			if(a.second > maxi){
				maxi = a.second;
			}
			if(a.second == maxi){
				t = a.first;
			}
		}
		//cout<<maxi<<','<<t<<endl;
		long long ans = 0LL;
		
		if(mp.size()!=0){
			ans += ((long long)maxi-1) * k;
			ans += t;
			ans++;
		}
		
		cout<<ans<<endl;
		
	}
	
	return 0;
}