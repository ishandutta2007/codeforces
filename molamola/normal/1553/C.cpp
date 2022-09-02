#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

int f(string s) {
	int c1 = 0, c2 = 0;
	int m1 = 5, m2 = 5;
	for(int i = 0; i < 5; i++) {
		char c = s[i * 2];
		if(c == '0') m1--;
		else c1++;
		if(c1 > m2 || c2 > m1) return i * 2 + 1;
		c = s[i * 2 + 1];
		if(c == '0') m2--;
		else c2++;
		if(c1 > m2 || c2 > m1) return i * 2 + 2;
	}
	return 10;
}

void solve() {
	string s, t;
	char buf[12];
	scanf("%s", buf);
	int ans = 10;
	rep(i, 1<<10) {
		string s = (string)buf;
		for(int j=0;j<10;j++) {
			if(s[j] == '?') {
				s[j] = ((i >> j) & 1) + '0';
			}
		}
		ans = min(ans, f(s));
	}
	printf("%d\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	rep(tt, T) {
		solve();
	}
	return 0;
}