#include<bits/stdc++.h>

using namespace std;

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define mid ((l + r) >> 1)
#define lc p + 1
#define rc p + ((mid - l + 1) << 1)

template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> par;
typedef long long LL;
typedef unsigned long long uLL;
typedef double db;
const int N = 2e5 + 10;
int SG(LL s, LL e) {
	if(s > e) return 1;
	if(e & 1) return !(s & 1);
	LL k = e / 2;
	if(k < s && s <= e) return (s & 1);
	if(k / 2 < s && s <= k) return 1;
	return SG(s, k / 2);
}

int main() {
	int t;
	int flag = 0, now = 0;
	for(scanf("%d", &t); t--; ) {
		LL s, e;
		scanf("%lld%lld", &s, &e);
		if(flag < 0) continue;
		int a = SG(s, e), b = SG(s, e / 2);
		a ^= now, b ^= now;
		if(flag && !a && !b) a = b = 1, now ^= 1, flag = 0;
		if(!a && !b) {
			flag = -1;
		}
		if(a && !b) now = 1;
		if(!a && b) now = 0;
		if(a && b) flag = 1;
	}
	if(flag > 0) puts("1 1");
	else if(flag == 0) {
		if(now) puts("1 0");
		else puts("0 1");
	} else puts("0 0");
	return 0;
}