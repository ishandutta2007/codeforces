#include <bits/stdc++.h>
#define broken cerr << "running on " << __FUNCTION__ <<" "<< __LINE__ << endl
#define x first
#define y second
#define mp make_pair
#define sz(a) int((a).size())
#define par pair<int, int>
#define poly vector<int>
#define i64 long long
#define u64 unsigned long long
using namespace std;
const int N = 2e5 + 10, P = 1e9 + 7;

int T, n, k;
int dp[N];


int power(int a, int b, int c = 1) {
	for(; b; b >>= 1, a = 1ll * a * a % P) 
		if(b & 1) 
			c = 1ll * c * a % P; 
	return c;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while(T--) {
		cin >> n >> k;
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		int prod = 1, pw1 = power(2, n), pw2 = power(2, n - 1);
		for(int i = 1; i <= k; i++) {
			if(n % 2 == 0) {
				dp[i] = 1ll * dp[i - 1] * (pw2 - 1 + P) % P;
				dp[i] = (dp[i] + prod) % P;
			} else {
				dp[i] = 1ll * dp[i - 1] * (pw2 + 1) % P;
			}
			prod = 1ll * prod * pw1 % P;
		}
		cout << dp[k] << endl;
	}
    return 0;
}