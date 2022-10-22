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

template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> P;
typedef long long LL;
typedef unsigned long long uLL;
typedef double db;
const int N = 1e6 + 10;
int n, a[N], b[N], c[2], p[N];
char s[N], t[N];
int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	rep(i, 1, n) a[i] = s[i] - '0', c[a[i]]++;
	rep(i, 1, n) b[i] = t[i] - '0', c[b[i]]--;
	if(c[0] || c[1]) return printf("-1\n"), 0;
	int now = -1, cnt = 0, tot = -1;
	rep(i, 1, n) {
		if(a[i] == b[i]) continue;
		if(a[i] == now) cnt++;
		else p[++tot] = cnt, now = a[i], cnt = 1;
	}
	p[++tot] = cnt;
	c[0] = c[1] = 0;
	now = 1, cnt = p[1];
	ckmax(c[now], cnt);
	rep(i, 2, tot) {
		if(now == (i & 1) || cnt == 0) now = (i & 1), cnt += p[i];
		else {
			int del = min(cnt, p[i]);
			cnt -= del, p[i] -= del;
			if(cnt == 0) now = (i & 1), cnt = p[i];
		}
		ckmax(c[now], cnt);
	}
	printf("%d\n", c[0] + c[1]);
	return 0;
}