#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int> edges[50];
vector<int> wgt[50];
int n;


int h(int a, int b, int c, int d){
	int v = a*1000000 + b*10000 + c*100 + d;
	return v;
}
map<int,int> dp;
int solve(int u, int v, int sub, int rest){
	int c = h(u, v, sub, rest);
	if(dp.find(c) != dp.end()) return dp[c];
	if(sub == 0 && rest == 0){
		dp[c] = 0;
		return dp[c];
	}
	if(sub == 0){
		dp[c] = 1e8;
		return dp[c];
	}
	if(edges[v].size() == 1){
		if(rest == 0){
			dp[c] = 0;
			return dp[c];
		}
		dp[c] = solve(v, u, rest, 0) + wgt[v][0];
		//cout << u << " " << v << " " << sub << " " << rest << endl;
		//cout << dp[c] << endl;
		return dp[c];
	}
	int s = -1; // can't finish
	int e = 1e8;
	while(s + 1 < e){
		int m = (s + e) / 2; // can you finish in m steps?
		int total = sub + rest;
		int numleft = sub;
		for(int f = 0; f < edges[v].size(); f++){
			if(edges[v][f] == u) continue;
			int t = 0;
			while(t < numleft){
				int rr = solve(v, edges[v][f], t+1, total - (t+1) );
				rr += wgt[v][f];
				if(rr > m){
					t++;
				} else {
					break;
				}
			}
			numleft -= t;
		}
		if(numleft > 0){
			e = m;
		} else {
			s = m;
		}
	}
	dp[c] = e;
	//cout << u << " " << v << " " << sub << " " << rest << endl;
	//cout << dp[c] << endl;
	return dp[c];
}
int freq[100];
int num(int u, int v){
	int ans = freq[v];
	for(int j = 0; j < edges[v].size(); j++){
		if(edges[v][j] == u) continue;
		ans += num(v, edges[v][j]);
	}
	return ans;
}
int main(){
	cin >> n;
	for(int i = 0; i < n-1; i++){
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
		wgt[u].push_back(w);
		wgt[v].push_back(w);
	}
	for(int i = 0; i < n; i++) freq[i] = 0;
	int s, m;
	cin >> s;
	s--;
	cin >> m;
	int x[m];
	for(int i = 0; i < m; i++){
		cin >> x[i];
		x[i]--;
		freq[x[i]]++;
	}
	int ans = 1e8;
	for(int j = 0; j < edges[s].size(); j++){
		int numsub = num(s, edges[s][j]);
		int cur = wgt[s][j] + solve(s, edges[s][j], numsub, m - numsub);
		ans = min(ans, cur);
	}
	cout << ans << endl;
}