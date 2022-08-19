#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	pair<int,int> b[n];
	for(int i = 0; i < n; i++){
		cin >> b[i].first >> b[i].second;
	}
	sort(b,b+n);
	int dp[n];
	int ans = 1;
	for(int i = 0; i < n; i++){
		int s = -1;
		int e = n;
		int r = b[i].first - b[i].second;
		while(s + 1 < e){
			int m = (s+e)/2;
			if(b[m].first >= r){
				e = m;
			} else {
				s = m;
			}
		}
		if(s == -1){
			dp[i] = 1;
		} else {
			dp[i] = dp[s]+1;
			ans = max(ans, dp[i]);
		}
	}
	cout << n-ans << endl;
	return 0;
}