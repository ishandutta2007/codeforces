#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define x first
#define y second
#define mp(a, b) make_pair(a, b)
#define read(a) scanf("%d", &a)

#define N 10005

int qry(vector<LL> &t) {
	printf("%d\n", (int)t.size());
//cerr << "::";
	for (auto v : t) printf("%lld ", v);
	printf("\n");
	fflush(stdout);
	int x;
	scanf("%d", &x);
	if (x < 0) exit(0);
	return x;
}

LL dp[6][N];

LL f(int k, LL x) {
	if (k == 0) return 1;
	x = min(x, 10000ll);
	if (k == 1) return x + 1;
	if (dp[k][x] != -1) return dp[k][x];
	LL now = x;
	for (int i = 0; i <= x; i++) {
		now += f(k - 1, now);
	}
	return dp[k][x] = now - x;
}

int main() {
	memset(dp, -1, sizeof dp);
/*	for (int j = 1; j <= 10; j++) 
		for (int i = 1; i <= 5; i++)
			cerr << "f " << i << " " << j << " : " << f(i, j) << endl;*/
	LL L = 1, R = 10004205361450474ll;
	for (int k = 5; k; k--) {
		vector <LL> q;
//		cerr << L << " " << R << endl;
		if (min(10000ll, L) >= R -L + 1) {
			for ( ;L <= R; q.push_back(L++));
		}
		else {
			LL now = L;
			for (int i = 0; i < min(10000ll, L); i++) {
				now += f(k - 1, now);
				q.push_back(min(now - 1, R));
				if (now - 1 >= R) break;
			}
		}
		int ret = qry(q);
		if (ret == 0) R = q[0] - 1;
		else if (ret == q.size()) L = q.back() + 1;
		else L = q[ret - 1] + 1, R = q[ret] - 1;
//		cerr << "after : " << L << " " << R << endl;
	}
	return 0;
}