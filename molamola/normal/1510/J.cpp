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

vector <pii> seg;
char A[100010];

int main() {
	scanf("%s", A + 1);
	int n = (int)strlen(A + 1);
	for(int i=1, p=-1;i<=n;i++) {
		if(A[i] == '#' && (i == 1 || A[i-1] == '_')) p = i;
		if(A[i] == '#' && (i == n || A[i+1] == '_')) seg.pb({p, i});
	}
	if(szz(seg) == 0) {
		puts("0");
		return 0;
	}
	int max_r = n;
	int m = szz(seg);
	for(int i=1;i<m;i++) max_r = min(max_r, seg[i].Fi - seg[i-1].Se - 2);
	if(seg[0].Fi == 1 && seg[m-1].Se == n) {
		int ok = 1;
		for(int i=1;i<m;i++) if(seg[i].Fi != seg[i-1].Se + 2) {
			ok = 0;
			break;
		}
		if(ok) {
			printf("%d\n", m);
			for(auto [l, r] : seg) printf("%d ", r - l + 1);
			puts("");
			return 0;
		}
	}
	auto output = [&](vector <int> ans) {
		vector <int> rns;
		for(int e : ans) {
			if(e > 0) rns.pb(e);
			else {
				int v = -e;
				while(v > 3) rns.pb(2), v -= 2;
				rns.pb(v);
			}
		}
		printf("%d\n", szz(rns));
		for(int e : rns) printf("%d ", e - 1); puts("");
	};
	for(int R = 1; R <= max_r; R++) {
		vector <int> ans;
		int sum = 0, ok = 1;
		for(auto [l, r] : seg) {
			int rst = l - sum - (R + 1);
			if(rst < 0) { ok = 0; break; }
			if(rst == 1 || (R == 1 && rst % 2)) { ok = 0; break; }
			if(rst > 0) ans.pb(-rst);
			sum += rst;
			int qi = r - l + 1 + R + 1;
			ans.pb(qi);
			sum += qi;
		}
		int rst = n + 1 - R - sum;
		if(rst < 0) ok = 0;
		if(rst == 1 || (R == 1 && rst % 2)) ok = 0;
		if(!ok) continue;
		if(rst > 0) ans.pb(-rst);
		output(ans);
		return 0;
	}
	puts("-1");
	return 0;
}