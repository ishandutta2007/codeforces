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

typedef long long LL;
typedef pair<int, int> par;
typedef unsigned long long uLL;
typedef double db;
const int N = 2e5 + 10;
int n, l, r;
int L[N], R[N];
void work() {
	scanf("%d%d%d", &n, &l, &r);
	for(int i = 1; i <= n; i++) L[i] = R[i] = 0;
	for(int i = 1; i <= l; i++) {
		int c;
		scanf("%d", &c);
		L[c]++;
	}
	for(int i = 1; i <= r; i++) {
		int c;
		scanf("%d", &c);
		R[c]++;
	}
	int step = abs(l - r) / 2;
	int cnt = step;
	if(step) {
		for(int i = 1; i <= n; i++) {
			if((l < r) == (L[i] < R[i])) {
				int d = abs(L[i] - R[i]);
				d /= 2;
				d = min(d, step);
				if(L[i] < R[i]) L[i] += d, R[i] -= d;
				else L[i] -= d, R[i] += d;
				step -= d;
			}
		}
	}
	int matc = 0;
	for(int i = 1; i <= n; i++) matc += abs(L[i] - R[i]);
	printf("%d\n", cnt + matc / 2);
	return;
}

int main() {
	int T;
	for(scanf("%d", &T); T--; ) work();
	return 0;
}