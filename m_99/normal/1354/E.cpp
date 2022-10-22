#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int n,m;
	cin>>n>>m;
	
	vector<int> x(3);
	cin>>x[0]>>x[1]>>x[2];
	
	vector<vector<int>> E(n,vector<int>());
	
	for(int i=0;i<m;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		u--;v--;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	
	vector<vector<int>> parent;
	vector<pair<int,int>> cnt;
	vector<int> color(n,-1);
	for(int i=0;i<n;i++){
		if(color[i]!=-1)continue;
		parent.push_back(vector<int>(1,i));
		cnt.emplace_back(1,0);
		color[i] = 0;
		queue<int> Q;
		Q.push(i);
		
		while(Q.size()!=0){
			int u = Q.front();
			Q.pop();
			for(int j=0;j<E[u].size();j++){
				int v = E[u][j];
				if(color[v]!=-1){
					if(color[v]!=color[u])continue;
					cout<<"NO"<<endl;
					return 0;
				}
				else{
					if(color[u]==0)cnt.back().second++;
					else cnt.back().first++;
					color[v] = color[u]^1;
					Q.push(v);
					parent.back().push_back(v);
				}
			}
		}
	}
	
	vector<vector<bool>> dp(parent.size()+1,vector<bool>(x[1]+1,false));
	dp[0][0] = true;
	
	for(int i=0;i<cnt.size();i++){
		for(int j=0;j<=x[1];j++){
			if(!dp[i][j])continue;
			for(int k=0;k<2;k++){
				int nx = j;
				if(k==0)nx += cnt[i].first;
				else nx += cnt[i].second;
				if(nx>x[1])continue;
				dp[i+1][nx] = true;
			}
		}
	}
	
	if(!dp.back().back()){
		cout<<"NO"<<endl;
		return 0;
	}
	
	vector<int> numbers;
	for(int i=0;i<x[0];i++)numbers.push_back(1);
	for(int i=0;i<x[2];i++)numbers.push_back(3);
	/*
	for(int i=0;i<=parent.size();i++){
		for(int j=0;j<=x[1];j++)cout<<dp[i][j]<<',';
		cout<<endl;
	}
	*/
	int now = x[1];
	vector<int> ans(n,0);
	for(int i=dp.size()-2;i>=0;i--){
		int c2;
		//cout<<now<<','<<cnt.back().first<<','<<cnt.back().second<<endl;
		if(now-cnt.back().first>=0&&dp[i][now-cnt.back().first]){
			now -= cnt.back().first;
			c2 = 0;
			cnt.pop_back();
		}
		else{
			now -= cnt.back().second;
			c2 = 1;
			cnt.pop_back();
		}
		for(int j=0;j<parent.back().size();j++){
			int t = parent.back()[j];
			if(color[t]==c2)ans[t] = 2;
			else{
				ans[t] = numbers.back();
				numbers.pop_back();
			}
		}
		parent.pop_back();
			
	}
	cout<<"YES"<<endl;
	for(int i=0;i<n;i++){
		printf("%d",ans[i]);
	}
	cout<<endl;
	
	
	return 0;
}