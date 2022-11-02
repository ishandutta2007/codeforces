# include <bits/stdc++.h>
using namespace std;

char s[1000010];

const int mod = 1e9 + 7;

int pw[1000010];

int main() {
	scanf("%s", s);
	int n = strlen(s);
	pw[0] = 1;
	for(int i = 1; i <= n; ++i)
		pw[i] = (pw[i-1] << 1) % mod;
	int cnt = 0;
	long long ans = 0;
	for(int i = 0; i < n; ++i) {
		if(s[i] == 'a') {
			cnt += 1;
		} else if(s[i] == 'b') {
			(ans += pw[cnt] - 1) %= mod;
		}
	}
	printf("%d\n", (int)ans);
}