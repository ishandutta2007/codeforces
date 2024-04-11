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
		
		vector<int> a(n);
		rep(i,n){
			cin>>a[i];
		}
		vector<vector<int>> ind;
		{
			vector<int> t = a;
			sort(t.begin(),t.end());
			t.erase(unique(t.begin(),t.end()),t.end());
			ind.resize(t.size());
			rep(i,n){
				ind[distance(t.begin(),lower_bound(t.begin(),t.end(),a[i]))].push_back(i);
			}
		}
	//	cout<<'a'<<endl;
		int ans = 0;
		vector<int> dp(ind.size(),-Inf);
		for(int i=1;i<ind.size();i++){
			dp[i] = ind[i].size();
			dp[i] += distance(ind[i-1].begin(),lower_bound(ind[i-1].begin(),ind[i-1].end(),ind[i][0]));
			if(ind[i-1].back() < ind[i][0]){
				dp[i] = max(dp[i],dp[i-1] + (int)ind[i].size());
			}
			
			
		}
		//cout<<'a'<<endl;
		for(int i=2;i<ind.size();i++){
			int t = dp[i-1];
			t += distance(lower_bound(ind[i].begin(),ind[i].end(),ind[i-1].back()),ind[i].end());
			ans = max(ans,t);
		}
		
		rep(i,ind.size())ans = max(ans,(int)ind[i].size());
		//cout<<'a'<<endl;
		rep(i,ind.size()-1){
			rep(j,ind[i].size()){
				int d = distance(lower_bound(ind[i+1].begin(),ind[i+1].end(),ind[i][j]),ind[i+1].end());
				d += j+1;
				ans = max(ans,d);
			}
			
		}
		
		//cout<<'a'<<endl;
		ans = n-ans;
		cout<<ans<<endl;
	}
		
	
	return 0;
}