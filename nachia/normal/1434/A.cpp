#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
LL A[6];
LL X[100000][7];

const LL INF = 1000000000000;

struct Query {
	int i, j;
	LL x;
};

bool operator<(Query l, Query r) { return l.x > r.x; }

int main() {
	rep(i, 6) cin >> A[i];
	sort(A, A + 6, greater<LL>());
	cin >> N;
	rep(i, N) {
		LL x; cin >> x;
		rep(j, 6) X[i][j] = x - A[j];
		X[i][6] = INF;
	}

	LL ans = INF;
	priority_queue<Query> G;

	LL slide_max = 0;
	rep(i, N) {
		G.push({ i,0,X[i][0] });
		slide_max = max(slide_max, X[i][0]);
	}

	rep(q, N * 6) {
		int i = G.top().i;
		int j = G.top().j;
		LL x = G.top().x;
		G.pop();

		ans = min(ans, slide_max - x);
		slide_max = max(slide_max, X[i][j + 1]);
		G.push({ i,j + 1,X[i][j + 1] });
	}

	cout << ans << endl;

	return 0;
}