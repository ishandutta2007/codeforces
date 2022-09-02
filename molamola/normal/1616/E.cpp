#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using t3 = tuple<int, int, int>;

const ll INF = 1e18;
int n;
char S[100010], T[100010];
int Tr[100010], chk[100010];
void upd(int x, int v) { for(int i=x;i<100010;i+=(i&-i)) Tr[i] += v; }
int read(int l, int r) {
	int res = 0;
	for(int i=r;i;i-=(i&-i)) res += Tr[i];
	for(int i=l-1;i;i-=(i&-i)) res -= Tr[i];
	return res;
}

void solve() {
	memset(Tr, 0, sizeof Tr);
	memset(chk, 0, sizeof chk);
	scanf("%d%s%s", &n, S + 1, T + 1);
	if(string(S+1) < string(T+1)) { puts("0"); return; }
	for(int i=1;i<=n;i++) upd(i, 1);
	set <int> S2[130];
	for(int i=1;i<=n;i++) S2[S[i]].insert(i);
	ll sum = 0, ans = INF;
	for(int i=1;i<=n;i++) {
		char t = T[i];
		char s = -1;
		int id = -1;
		for(char s2=t-1;s2>='a';s2--) {
			if(szz(S2[s2])) {
				if(id == -1 || id > *S2[s2].begin()) {
					id = *S2[s2].begin();
					s = s2;
				}
			}
		}
		if(s != -1) {
			ans = min(ans, sum + read(1, id - 1));
		}
		if(szz(S2[t]) && (id == -1 || id > *S2[t].begin())) {
			id = *S2[t].begin();
			S2[t].erase(S2[t].begin());
			sum += read(1, id - 1);
			upd(id, -1);
		}
		else break;
	}
	printf("%lld\n", ans == INF ? -1 : ans);
}

int main() {
	int TC; scanf("%d", &TC);
	for(int t=1;t<=TC;t++) {
		solve();
	}
	return 0;
}