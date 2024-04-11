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
		vector<int> l(n),r(n);
		vector<int> t;
		rep(i,n){
			cin>>l[i]>>r[i];
			t.push_back(l[i]);
			t.push_back(r[i]);
		}
		sort(t.begin(),t.end());
		t.erase(unique(t.begin(),t.end()),t.end());
		vector b(t.size(),vector<bool>(t.size(),false));
		vector<vector<int>> rs(t.size());
		rep(i,n){
			l[i] = distance(t.begin(),lower_bound(t.begin(),t.end(),l[i]));
			r[i] = distance(t.begin(),lower_bound(t.begin(),t.end(),r[i]));
			b[l[i]][r[i]] = true;
			rs[l[i]].push_back(r[i]);
		}
		rep(i,t.size())sort(rs[i].begin(),rs[i].end());
		vector dp(t.size(),vector<int>(t.size(),-1));
		
		rep(i,t.size()){
			if(b[i][i])dp[i][i] = 1;
			else dp[i][i] = 0;
		}
		
		for(int i=1;i<t.size();i++){
			rep(j,t.size()){
				int l = j;
				int r = i+j;
				if(r>=t.size())break;
				
				dp[l][r] = max(dp[l][r],dp[l+1][r]);
				rep(k,rs[l].size()){
					if(rs[l][k]+1<=r){
						
						dp[l][r] = max(dp[l][r],dp[l][rs[l][k]] + dp[rs[l][k]+1][r]);
						
					}
					else break;
				}
				
				if(b[l][r])dp[l][r]++;
				
			}
			
			
		}
		
		
		
		printf("%d\n",dp[0].back());
		
	}
	
	return 0;
}