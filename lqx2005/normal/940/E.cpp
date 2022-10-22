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
int n, c, a[N];
LL dp[N];
deque<int> q;
int main() {
	scanf("%d%d", &n, &c);
	LL s = 0;
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), s += a[i];
	dp[0] = 0;
	for(int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		while(!q.empty() && q.front() <= i - c) q.pop_front();
		while(!q.empty() && a[q.back()] > a[i]) q.pop_back();
		q.push_back(i);
		if(i >= c) {
			dp[i] = max(dp[i - c] + a[q.front()], dp[i]);
		}
	}
	printf("%lld\n", s - dp[n]);
	return 0;
}