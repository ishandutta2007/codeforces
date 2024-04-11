#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

int n, m, s[5050];
vector <int> h[5050];
const int mod = 1e9 + 7;


void solve() {
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) scanf("%d", s + i);
	rep(i, m) {
		int ff, hh;
		scanf("%d%d", &ff, &hh);
		h[ff].pb(hh);
	}
	for(int i=1;i<=n;i++) sort(all(h[i]));
	pii res = pii(0, 0);
	for(int i=0;i<=n;i++) {
		pii ans = pii(0, 1);
		auto upd = [&](pii a) {
			ans.Fi += a.Fi;
			ans.Se = (ll)ans.Se * a.Se % mod;
		};

		int cl[5050] = {}, cr[5050] = {};
		for(int j=1;j<=i;j++) cl[s[j]]++;
		for(int j=i+1;j<=n;j++) cr[s[j]]++;

		int ok = 1;
		for(int j=1;j<=n;j++) {
			int a = cl[j], b = cr[j];
			if(i && j == s[i]) {
				int fd = 0;
				for(int e : h[j]) if(e == a) fd = 1;
				if(fd == 0) {
					ok = 0; break;
				}
				int cnt = 0;
				for(int e : h[j]) if(e != a && e <= b) ++cnt;
				if(cnt) upd(pii(1, cnt));
			}
			else {
				if(szz(h[j]) == 0) continue;
				if(a > b) swap(a, b);
				if(h[j][0] > b) continue;
				int ca = 0, cb = 0;
				for(int e : h[j]) if(e <= a) ++ca;
				for(int e : h[j]) if(e <= b) ++cb;
				if(szz(h[j]) >= 2 && h[j][0] <= a && h[j][1] <= b) {
					upd(pii(2, ca * (cb-1)));
				}
				else {
					upd(pii(1, ca + cb));
				}
			}
		}

		if(ok == 0) continue;
		if(i) ans.Fi += 1;

		if(res.Fi < ans.Fi) res = ans;
		else if(res.Fi == ans.Fi) {
			res.Se = (res.Se + ans.Se) % mod;
		}
	}
	printf("%d %d\n", res.Fi, res.Se);
}

int main() {
	int T = 1; //scanf("%d", &T);
	for(int t=1;t<=T;t++) {
		solve();
	}
	return 0;
}