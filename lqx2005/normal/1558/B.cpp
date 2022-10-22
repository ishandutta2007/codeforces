#include<bits/stdc++.h>
#define sz(a) int((a).size())
#define x first
#define y second
#define pi pair<int, int> 
#define vi vector<int>
#define db double
#define i64 long long
#define u64 unsigned long long
using namespace std;
const int N = 4e6 + 10;
int n, m, dp[N], pd[N];
int main() {
	cin >> n >> m;
	dp[1] = 1, dp[2] = m - 1;
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		(dp[i] += dp[i - 1]) %= m;
		pd[i] = (dp[i] + sum) % m;
		for(int j = 2; j * i <= n; j++) {
			(dp[j * i] += pd[i]) %= m;
			if(j * (i + 1) <= n) (dp[j * (i + 1)] += m - pd[i]) %= m;
		}
		(sum += pd[i]) %= m;
	}
	cout << pd[n] << endl;
	return 0;
}