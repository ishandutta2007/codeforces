#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000

struct edge{
	int toi,toj;
	long long cost;
	long long label;
};

int main(){
	
	int T;
	cin>>T;
	
	for(int _=0;_<T;_++){
		int n,k;
		cin>>n>>k;
		
		vector<vector<long long>> a;
		
		for(int i=0;i<n;i++){
			int x,y;
			cin>>x>>y;
			a.push_back({y,x,i});
		}
		
		sort(a.begin(),a.end());
		
		vector<vector<long long>> dp(n+1,vector<long long>(k+1,-Inf));
		dp[0][0] = 0;
		
		vector<vector<vector<edge>>> E(n+1,vector<vector<edge>>(k+1,vector<edge>()));
		
		for(int i=0;i<n;i++){
			for(int j=0;j<=k;j++){
				if(dp[i][j]==-Inf)continue;
				
				dp[i+1][j] = max(dp[i+1][j],dp[i][j]+a[i][0]*(k-1));
				E[i+1][j].push_back({i,j,a[i][0]*(k-1),-(a[i][2]+1)});
				if(j!=k){
					dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j] + a[i][1] + a[i][0]*j);
					E[i+1][j+1].push_back({i,j,a[i][1] + a[i][0] * j,a[i][2]+1});
				}
			}
		}

		vector<int> ans_plus,ans_minus;
		int ni = n,nj = k;
		while(ni!=0||nj!=0){
			for(int i=0;i<E[ni][nj].size();i++){
				auto &e = E[ni][nj][i];
				if(dp[e.toi][e.toj] + e.cost == dp[ni][nj]){
					if(e.label>0)ans_plus.push_back(e.label);
					else ans_minus.push_back(-e.label);
					ni = e.toi;
					nj = e.toj;
					break;
				}
			}
		}
		vector<int> ans;
		while(ans_plus.size()!=1){
			ans.push_back(ans_plus.back());
			ans_plus.pop_back();
		}
		for(int i=0;i<ans_minus.size();i++){
			int t = ans_minus[i];
			ans.push_back(t);
			ans.push_back(-t);
		}
		ans.push_back(ans_plus.back());
		
		cout<<ans.size()<<endl;
		for(int i=0;i<ans.size();i++){
			if(i!=0)cout<<' ';
			cout<<ans[i];
		}
		cout<<endl;
			
	}
	
	return 0;
}