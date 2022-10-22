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
const int N = 1e5 + 10;
int n, m, x;
int h[N];
int s[N];
priority_queue<par, vector<par>, greater<par> > q;
void work() {
	while(!q.empty()) q.pop();
	scanf("%d%d%d", &n, &m, &x);
	for(int i = 1; i <= n; i++) scanf("%d", &h[i]);
	for(int i = 1; i <= m; i++) s[i] = 0, q.push(mp(0, i));
	printf("YES\n");
	for(int i = 1; i <= n; i++) {
		int u = q.top().y;
		q.pop();
		printf("%d ", u);
		s[u] += h[i];
		q.push(mp(s[u], u));
	}
	printf("\n");
	return;
}

int main() {
	int T;
	for(scanf("%d", &T); T--; ) work();
	return 0;
}