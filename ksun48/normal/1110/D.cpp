#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int freq[1200000];
int MAXN = 1100000;


int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<LL> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int x : a) freq[x+5]++;
	vector<vector<int> > dp(3, vector<int>(3, -1e7));
	dp[0][0] = 0;
	for(int b = 3; b < MAXN; b++){
		vector<vector<int> > ndp(3, vector<int>(3, -1e7));
		for(int r = 0; r < 3; r++){
			for(int s = 0; s < 3; s++){
				if(dp[r][s] < 0) continue;
				for(int t = 0; t < 3; t++){
					if(t > freq[b + 2]) continue;
					if(t + s > freq[b + 1]) continue;
					if(t + s + r > freq[b]) continue;
					int nleft = freq[b] - r - s - t;
					nleft /= 3;
					ndp[s][t] = max(ndp[s][t], dp[r][s] + nleft + t);
				}
			}
		}
		dp = ndp;
	}
	int ans = -1;
	for(int r = 0; r < 3; r++){
		for(int s = 0; s < 3; s++){
			ans = max(ans, dp[r][s]);
		}
	}
	cout << ans << '\n';
}