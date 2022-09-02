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

const int L = 1e6 + 10;
int n, q, a[200020];
int pr[L + 10];
int pp[L + 10];
int Find(int x) { return pp[x] == x ? x : pp[x] = Find(pp[x]); }

void solve() {
	for(int i=1;i<=L;i++) pr[i] = 1;
	for(int i=2;i<=L;i++) {
		if(pr[i] != 1) continue;
		for(int j=i;j<=L;j+=i) pr[j] = i;
	}
	scanf("%d%d", &n, &q);
	for(int i=1;i<=n;i++) scanf("%d", a + i);
	for(int i=1;i<=L;i++) pp[i] = i;
	auto fct = [&](int x) {
		vector <int> li;
		while(x > 1) {
			int t = pr[x];
			if(pr[t] == t) li.pb(t);
			x /= t;
		}
		li.resize(unique(all(li)) - li.begin());
		return li;
	};
	for(int i=1;i<=n;i++) {
		int x = a[i];
		auto li = fct(x);
		int m = szz(li);
		for(int v=1;v<m;v++) {
			pp[Find(li[v])] = Find(li[0]);
		}
	}
	set<pii> S;
	for(int i=1;i<=n;i++) {
		int x = a[i];
		auto l1 = fct(x), l2 = fct(x + 1);
		vector <int> w;
		for(int e : l1) w.pb(Find(e));
		for(int e : l2) w.pb(Find(e));
		sort(all(w)); w.resize(unique(all(w)) - w.begin());
		int m = szz(w);
		rep(j, m) rep(k, j) {
			S.insert(pii(w[k], w[j]));
		}
	}
	rep(qq, q) {
		int s, t;
		scanf("%d%d", &s, &t);
		s = pr[a[s]], t = pr[a[t]];
		if(Find(s) == Find(t)) puts("0");
		else {
			s = Find(s), t = Find(t);
			if(s > t) swap(s, t);
			if(S.find(pii(s, t)) == S.end()) puts("2");
			else puts("1");
		}
	}
}

int main() {
	int TC = 1; //scanf("%d", &TC);
	rep(tt, TC) {
		solve();
	}
	return 0;
}