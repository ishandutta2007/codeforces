#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define pb push_back
using namespace std;
typedef long long i64;
typedef double db;
const int N = 1e6 + 10;
int n, a[N], b[N];
int p[N], vis[N], tot = 0;
vector<int> fac[N], cnt[N];
char str[N];
int tag[N], mx[N], mn[N];
vector<int> s[N];
multiset<int> pos;
void sieve(int n) {
	vis[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(!vis[i]) p[++tot] = i, fac[i].push_back(i), cnt[i].push_back(1);
		for(int j = 1; j <= tot && i * p[j] <= n; j++) {
			vis[i * p[j]] = 1;
			fac[i * p[j]] = fac[i];
			cnt[i * p[j]] = cnt[i];
			if(i % p[j] == 0) {
				cnt[i * p[j]].back()++;
				break;
			}
			fac[i * p[j]].push_back(p[j]);
			cnt[i * p[j]].push_back(1);
		}
	}
	return;
}

int main() {
	sieve(N - 10);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	scanf("%s", str + 1);
	for(int i = 1; i <= n; i++) b[i] = str[i] == '*' ? 1 : -1;
	i64 ans = 0;
	for(int i = n; i >= 1; i--) {
		for(int j = 0; j < sz(fac[a[i]]); j++) {
			int d = fac[a[i]][j], c = cnt[a[i]][j] * b[i];
			tag[d] += c;
			mn[d] = min(mn[d], -tag[d]);
			mx[d] = max(mx[d], -tag[d]);
		}
	}
	memset(tag, 0, sizeof(tag));
	for(int i = 1; i <= tot; i++) s[p[i]].resize(mx[p[i]] - mn[p[i]] + 1, n + 1);
	for(int i = n; i >= 1; i--) {
		int x = n;
		for(int j = 0; j < sz(fac[a[i]]); j++) {
			int d = fac[a[i]][j], c = cnt[a[i]][j] * b[i];
			s[d][-tag[d] - mn[d]] = min(s[d][-tag[d] - mn[d]], i);
			int l = -tag[d];
			tag[d] += c;
			int r = -tag[d];
			if(l > r) {
				for(int k = r; k <= l - 1; k++) {
					if(s[d][k - mn[d]] <= n) {
						pos.erase(pos.find(s[d][k - mn[d]]));
					}
				}
			} else {
				for(int k = r - 1; k >= l; k--) {
					if(s[d][k - mn[d]] <= n) {
						pos.insert(s[d][k - mn[d]]);
					}
				}
			}
		}
		if(pos.empty()) ans += n + 1 - i;
		else ans += (*pos.begin() - i);
	}
	printf("%lld\n", ans);
	return 0;
}