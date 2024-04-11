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

struct seg {
	ll l, r, x;
};

int n;
ll h[1000010];
vector <seg> V;
ll ans[1000010];

int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%lld", h + i);
	V.pb({1, 1, h[1] - 1});
	for(int i=2;i<=n;i++) {
		ll ph = V.back().r + V.back().x;
		if(ph == h[i]) {
			V.pb({i, i, h[i] - i});
			continue;
		}
		V.back().r = i;
		ll add = h[i] - ph - 1;
		if(add == 0) continue;
		while(szz(V)) {
			if(szz(V) == 1) {
				ll x = add / i;
				V.back().x += x;
				add %= i;
				break;
			}
			if(i - V[szz(V)-2].r <= add) {
				add -= i - V[szz(V)-2].r;
				V.pop_back();
				V.back().r = i;
			}
			else break;
		}
		if(add) {
			ll l = V.back().l, vx = V.back().x;
			V.back().r = l + add - 1;
			V.back().x++;
			if(szz(V) > 1 && V.back().x == V[szz(V)-2].x) {
				V.pop_back();
				V.back().r = l + add - 1;
			}
			if(l + add <= i) {
				V.pb({l + add, i, vx});
			}
		}
	}
	for(auto [l, r, x] : V) {
		for(ll i=l;i<=r;i++) ans[i] = x + i;
	}
	for(int i=1;i<=n;i++) printf("%lld ", ans[i]); puts("");
	return 0;
}