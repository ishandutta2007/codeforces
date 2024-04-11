#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		
		int n;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		
		vector<vector<long long>> dp(n+2,vector<long long>(n+2,0));
		dp[0][0] = 1;
		
		for(int i=0;i<n;i++){
			vector<pair<pair<int,int>,long long>> next;
			next.emplace_back(make_pair(a[i],0),dp[0][0]);
			for(int j=1;j<=n;j++){
				next.emplace_back(make_pair(j,a[i]),dp[j][0]);
				next.emplace_back(make_pair(n+1,j),dp[a[i]][j]);
			}
			next.emplace_back(make_pair(n+1,n+1),dp[n+1][a[i]]);
			
			for(int j=0;j<next.size();j++){
				dp[next[j].first.first][next[j].first.second]+=next[j].second;
			}
			
		}
		cout<<dp.back().back()<<endl;
		
	}
	
	return 0;
}