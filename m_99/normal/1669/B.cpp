#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000



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
			mp[a]++;
		}
		int ans = -1;
		for(auto a:mp){
			if(a.second>=3)ans = a.first;
		}
		cout<<ans<<endl;
		
		
	}
	
	
    return 0;
}