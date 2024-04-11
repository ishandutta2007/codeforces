#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int k[110000];
int a, b, h, w, n;
map<pair<pair<int,int>,int>, int> dp;
int solve(int c, int d, int i){
	pair<pair<int,int>,int> v = make_pair(make_pair(c,d),i);
	if(dp.find(v) != dp.end()) return dp[v];
	if(c == 1 && d == 1){
		dp[v] = i;
		return dp[v];
	}
	if(i == n){
		dp[v] = 1e7;
		return dp[v];
	}
	if(c == 1){
		dp[v] = solve(c,(d+k[i]-1)/k[i],i+1);
		return dp[v];
	}
	if(d == 1){
		dp[v] = solve((c+k[i]-1)/k[i],d,i+1);
		return dp[v];
	}
	dp[v] =  min(solve(c,(d+k[i]-1)/k[i],i+1),solve((c+k[i]-1)/k[i],d,i+1));	
	return dp[v];
}
int main(){	
	cin >> a >> b >> h >> w >> n;
	int c, d;

	for(int i = 0; i < n; i++) cin >> k[i];
	sort(k,k+n);
	reverse(k,k+n);
	int ans = 1e7;
	for(int i = 0; i < 2; i++){
		c = (a+h-1)/h;
		d = (b+w-1)/w;
		swap(h,w);
		ans = min(ans,solve(c,d,0));
	}
	if(ans == 1e7){
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}

}