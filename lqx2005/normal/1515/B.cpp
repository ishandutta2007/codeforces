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
int n;
int work() {
	scanf("%d", &n);
	if(n & 1) return 0; 
	int m = llround(sqrt(n / 2));
	if(m * m == n / 2) return 1;
	if(n % 4) return 0;
	m = llround(sqrt(n / 4));
	if(m * m == n / 4) return 1;
	return 0;
}

int main() {
	int T;
	for(scanf("%d", &T); T--; ) printf(work() ? "YES\n" : "NO\n");
	return 0;
}