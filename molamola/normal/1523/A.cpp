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

char buf[1010];

void solve() {
	int n, m;
	string s;
	scanf("%d%d", &n, &m);
	scanf("%s", buf);
	s = (string)buf;
	while(m--) {
		string s2;
		s2.resize(n);
		rep(i, n) {
			if(s[i] == '1') s2[i] = '1';
			else {
				int c = 0;
				if(i > 0 && s[i-1] == '1') ++c;
				if(i+1 < n && s[i+1] == '1') ++c;
				if(c == 1) s2[i] = '1';
				else s2[i] = '0';
			}
		}
		if(s == s2) break;
		s = s2;
	}
	printf("%s\n", s.c_str());
}

int main() {
	int T; scanf("%d", &T);
	rep(tt, T) {
		solve();
	}
	return 0;
}