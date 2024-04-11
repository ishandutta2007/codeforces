#include<bits/stdc++.h>

using namespace std;

#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()
#define x first
#define y second
#define mp make_pair
#define pb push_back

template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> par;
typedef long long LL;
typedef unsigned long long uLL;
typedef double db;
const int N = 1e5 + 10;
int n;
int a[N], c[N], id[N];

int cmp(int x, int y) {return a[x] < a[y]; }

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d%d", &a[i], &c[i]), id[i] = i;
	sort(id, id + n, cmp);
	LL ans = 0;
	int now = a[id[0]] + c[id[0]];
	for(int i = 1; i < n; i++) {
		int j = id[i];
		if(a[j] <= now) now = max(now, a[j] + c[j]);
		else ans += a[j] - now, now = a[j] + c[j];
	}
	for(int i = 0; i < n; i++) ans += c[i];
	printf("%lld\n", ans);
	return 0;
}