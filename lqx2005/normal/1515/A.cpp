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

template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> par;
typedef long long LL;
typedef unsigned long long uLL;
typedef double db;
const int N = 100 + 10;
int n, x;
int w[N];
void work() {
	scanf("%d%d", &n, &x);
	int s = 0;
	for(int i = 1; i <= n; i++) scanf("%d", &w[i]), s += w[i];
	if(s == x) return printf("NO\n"), void();
	s = 0;
	for(int i = 1; i <= n; i++) {
		s += w[i];
		if(s == x) {
			swap(w[i], w[i + 1]);
			break;
		}
	}
	printf("YES\n");
	for(int i = 1; i <= n; i++) printf("%d ", w[i]);
	printf("\n");
	return;
}

int main() {
	int T;
	for(scanf("%d", &T); T--; ) work();
	return 0;
}