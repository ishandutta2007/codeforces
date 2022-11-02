#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int N, A[500];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	REP(i, N) cin >> A[i];

	vii order(N);
	REP(i, N) order[i] = ii(A[i], i + 1);
	sort(all(order));

	if (order[N-1].x == 1) return printf("NO\n"), 0;

	vi sdeg(N, 0);
	sdeg[N - 1] = order[N - 1].x;
	for (int i = N - 2; i >= 0; i--) {
		sdeg[i] = sdeg[i + 1] + order[i].x;
	}

	int rm = 0;
	for (int m = 1; m <= N - 2; m++) {
		if (sdeg[N - m] >= N + m - 2 && order[N - m].x > 1) rm = max(rm, m);
	}

	if (rm == 0) return printf("NO\n"), 0;

	printf("YES %d\n", rm + 1);

	int nedges = N - 1; // a tree
	printf("%d\n", nedges);

	vi path(rm + 2);
	path[0] = 0;
	path[rm + 1] = 1;
	REP(i, rm) path[i + 1] = N - i - 1;

	REP(i, rm + 1) {
		int aa = path[i], bb = path[i + 1];
		printf("%d %d\n", order[aa].y, order[bb].y);
		order[aa].x--;
		order[bb].x--;
	}

	for (int i = 2; i < N - rm; i++) {
		bool val = false;
		for (int j = N - rm; j < N; j++) {
			if (order[j].x > 0) {
				printf("%d %d\n", order[i].y, order[j].y);
				order[i].x--;
				order[j].x--;
				val = true;
				break;
			}
		}
		assert(val);
	}

	return 0;
}