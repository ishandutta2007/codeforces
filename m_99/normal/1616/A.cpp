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
		
		map<int,int> mp;
		rep(i,n){
			int a;
			cin>>a;
			mp[abs(a)]++;
		}
		
		int ans = 0;
		for(auto a:mp){
			if(a.first==0)ans += min(1,a.second);
			else ans += min(2,a.second);
		}
		cout<<ans<<endl;
		
	}
	
	return 0;
}