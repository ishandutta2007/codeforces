#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000	

vector<vector<int>> E;
vector<int> arrange;


void eraseDFS(int now,int p){
	vector<int> nxt;
	for(int i=0;i<E[now].size();i++){
		int to = E[now][i];
		if(to==p)continue;
		nxt.push_back(to);
		eraseDFS(to,now);
	}
	E[now] = nxt;
	arrange.push_back(now);
}

map<int,int> mp,mp2;
vector<pair<int,int>> dp;
int check(int k){
	static vector<int> memo(100001,-1);
	if(memo[k]==-1){
		
		fill(dp.begin(),dp.end(),make_pair(0,0));
		for(int i=0;i<arrange.size();i++){
			int now = arrange[i];
			int A=0,B=0;
			for(int j=0;j<E[now].size();j++){
				int to = E[now][j];
				dp[now].second += dp[to].second;
				if(A<dp[to].first){
					swap(A,B);
					A = dp[to].first;
				}
				else if(B<dp[to].first)B = dp[to].first;
			}
			if(A+B+1>=k)dp[now].second++;
			else dp[now].first = A+1;
		}		
		memo[k] = dp[0].second;
		if(mp.count(memo[k])){
			mp[memo[k]] = min(mp[memo[k]],k);
			mp2[memo[k]] = max(mp2[memo[k]],k);
		}
		else{
			mp[memo[k]] = k;
			mp2[memo[k]] = k;
		}
	}
	
	return memo[k];
}

int main(){

	int n;
	cin>>n;
	
	E.resize(n,vector<int>());
	dp.resize(n);
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		a--;b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	
	eraseDFS(0,-1);
	mp[-1] = n+1;

	
	vector<int> ans(n);
	for(int i=0;i<n;i++){
		int ok = i+1;
		int v = check(ok);
		if(i<500){
			ans[i] = v;
			continue;
		}
		auto it = mp.lower_bound(v);
		it--;
		int ng = it->second;
		
		it = mp2.lower_bound(v);
		ok = max(ok,it->second);

		while(ng-ok>1){
			int mid = (ok+ng)/2;
			if(v==check(mid)){
				ok = mid;
			}
			else ng = mid;
		}
		for(int j=i;j<ok;j++)ans[j] = v;
		i = ok-1;
	}
	
	rep(i,n){
		printf("%d\n",ans[i]);
	}
	
	return 0;
}