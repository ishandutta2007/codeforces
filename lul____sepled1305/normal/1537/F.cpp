#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

bool color(vector<int> G[], int dp[], int n) {
	for(int i=0;i<n;i++)
		dp[i] = -1;
	queue<int> qu;
	dp[0] = 0;
	qu.push(0);
	while(!qu.empty()) {
		int node = qu.front();
		qu.pop();
		for(auto it: G[node]) {
			if(dp[it] == -1) {
				dp[it] = 1-dp[node];
				qu.push(it);
			}
		}
	}
	bool pass = true;
	for(int i=0;i<n;i++) 
		for(auto it: G[i])
			if(dp[i] == dp[it])
				pass = false;
	return pass;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,m;
		cin>>n>>m;
		long long w[n], t[n];
		vector<int> G[n];
		for(int i=0;i<n;i++)
			cin>>w[i];
		for(int i=0;i<n;i++)
			cin>>t[i];
		for(int i=0;i<m;i++) {
			int a,b; cin>>a>>b; a--,b--;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		//Check Bipartite-ness
		int dp[n];
		bool pass = true;
		
		long long sumA = 0, sumB = 0;
		for(int i=0;i<n;i++)
			sumA += w[i], sumB += t[i];
		
		if(abs(sumA%2) != abs(sumB%2))
			pass = false;
		
		if(color(G,dp,n)) {
			long long changeA = 0, changeB = 0;
			for(int i=0;i<n;i++) {
				if(dp[i] == 0) {
					changeA += (t[i]-w[i]);
				}
				else {
					changeB += (t[i]-w[i]);
				}
			}
			if(changeA != changeB)
				pass = false;
		}
		
		if(pass)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}