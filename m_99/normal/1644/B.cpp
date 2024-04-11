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
		
		vector<vector<int>> ans(n);
		if(n==3){
			ans[0] = {3,2,1};
			ans[1] = {3,1,2};
			ans[2] = {1,3,2};
		}
		else{
			rep(i,n)ans[0].push_back(n-i);
			for(int i=1;i<n;i++){
				ans[i] = ans[i-1];
				int t = ans[i].back();
				ans[i].pop_back();
				ans[i].insert(ans[i].begin(),t);
			}
		}
		rep(i,n){
			rep(j,n){
				if(j!=0)cout<<' ';
				cout<<ans[i][j];
			}
			cout<<endl;
		}
		
	}
	
	return 0;
}