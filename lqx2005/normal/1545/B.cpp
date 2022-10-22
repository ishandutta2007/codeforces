#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10, P = 998244353;
char s[N];

int power(int a, int b, int c = 1) {
	for(; b; b >>= 1, a = 1ll * a * a % P)
		if(b & 1) 
			c = 1ll * c * a % P;
	return c;
}

int solve() {
	int n;
	cin >> n >> (s + 1);
	int cnt = 0, sum = 0, white = 0;
	for(int i = 1; i <= n; i++) {
		if(s[i] == '1') {
			cnt++;
			if(cnt == 2) cnt = 0, sum++;
		} else {
			white++;
			cnt = 0;
		}
	}
	int ans = 1;
	for(int i = 1; i <= sum; i++) ans = 1ll * ans * (white + i) % P;
	for(int i = 1; i <= sum; i++) ans = 1ll * ans * power(i, P - 2) % P;
	return ans;
}

int main() {
	int T;
	for(cin >> T; T--; ) printf("%d\n", solve());
	return 0;	
}