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
		
		map<int,vector<int>> mp;
		rep(i,n){
			int a;
			scanf("%d",&a);
			mp[a].push_back(i);
		}
		
		int ans = -1;
		for(auto a:mp){
			auto v = a.second;
			if(v.size()<=1)continue;
			rep(i,v.size()-1){
				ans = max(ans,1+min(v[i] , v[i+1]) + min(n-1-v[i],n-1-v[i+1]));
			}
		}
		printf("%d\n",ans);
		
		
	}
	
	return 0;
}