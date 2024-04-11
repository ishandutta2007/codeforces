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
		
		vector<vector<int>> ind(n,vector<int>(1,0));
		rep(i,n){
			int a;
			scanf("%d",&a);
			a--;
			ind[a].push_back(i+1);
		}
		
		rep(i,n){
			ind[i].push_back(n+1);
		}
		
		int ans = Inf;
		rep(i,n){
			if(ind[i].size()==2)continue;
			int temp = 0;
			rep(j,ind[i].size()-1){
				if(ind[i][j]+1!=ind[i][j+1])temp++;
			}
			ans = min(ans,temp);
		}
		cout<<ans<<endl;
			
	}
	
	return 0;
}