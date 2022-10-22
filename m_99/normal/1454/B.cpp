#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
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
			mp[a].push_back(i+1);
		}
		int ans = -1;
		for(auto a:mp){
			if(a.second.size()==1){
				ans = a.second[0];
				break;
			}
		}
		
		printf("%d\n",ans);
		
		
		
	}
	
	return 0;
}