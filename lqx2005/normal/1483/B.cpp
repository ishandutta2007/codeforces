#include<bits/stdc++.h>

using namespace std;

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()
#define sit set<int>::iterator
template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> P;
typedef long long LL;
typedef unsigned long long uLL;
typedef double db;
const int N = 1e5 + 10;
int n, a[N], ans[N], tot = 0;
int l[N], r[N];
set<int> t;
int nxt(int x, set<int> &s) {
	sit it = s.lower_bound(x);
	if(it == s.end()) return *s.begin();
	return *it;
}

void work() {
	t.clear();
	scanf("%d", &n);
	rep(i, 0, n - 1) scanf("%d", &a[i]), l[i] = (i - 1 + n) % n, r[i] = (i + 1) % n;
	rep(i, 0, n - 1) if(__gcd(a[i], a[(i + 1) % n]) == 1) t.insert((i + 1) % n);
	tot = 0;
	int now = 1;
	while(t.size() >= 1 && tot < n) {
		int pos = nxt(now, t);
		ans[++tot] = pos;
		now = r[r[pos]];
		t.erase(pos);
		int pre = l[pos], suf = r[pos];
		r[l[pos]] = r[pos], l[r[pos]] = l[pos];
		if(t.find(suf) != t.end()) t.erase(suf);
		if(__gcd(a[pre], a[suf]) == 1) t.insert(suf);
	}
	printf("%d ", tot);
	rep(i, 1, tot) printf("%d ", ans[i] + 1);
	printf("\n");
	return;
}

int main() {
	int T;
	scanf("%d", &T);
	for(; T--; ) work();
	return 0;
}