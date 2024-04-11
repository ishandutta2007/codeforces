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

void solve() {
	string s, t;
	cin >> s >> t;
	for(int i=0;i<szz(s);i++) {
		for(int j=0;i+j<szz(s) && j+1<=szz(t);j++) {
			int r = szz(t) - (j + 1);
			if(r < 0) continue;
			int p = 0, ok = 1;
			for(int k=i;k<=i+j && ok;k++) {
				if(p >= szz(t) || t[p++] != s[k]) {
					ok = 0;
				}
			}
			for(int k=i+j-1;k>=i+j-r && ok;k--) {
				if(p >= szz(t) || t[p++] != s[k]) {
					ok = 0;
				}
			}
			if(ok) {
				puts("YES");
				return;
			}
		}
	}
	puts("NO");
}

int main() {
	int T; scanf("%d", &T);
	rep(tt, T) {
		solve();
	}
	return 0;
}