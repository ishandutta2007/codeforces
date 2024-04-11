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

const int maxn = 1000;
int N, M, C, I;
int A[maxn] = {}, L, R;

int findIdx(int x) {
	if (I == 0) {
		L = 0;
		R = 0;
	}

	if (x <= C/2) {
		// fill left
		if (L == 0) {
			L = 1;
			return 0;
		}
		if (x < A[0]) return 0;

		int ret = upper_bound(A, A + L, x) - A;
		if (ret == L) ++L;
		return ret;
	} else {
		// fill right
		if (R == 0) {
			R = 1;
			return N - 1;
		}
		if (x > A[N - 1]) return N - 1;

		int ret = lower_bound(A + N - R, A + N, x) - A;
		if (ret == N - R) ++R;
		return ret - 1;
	}
}

void io() {
	int x;
	scanf("%d", &x);

	int ans = findIdx(x);
	A[ans] = x;
	printf("%d\n", ans + 1);
	fflush(stdout);

#ifdef LOCAL
	for (int i = 0; i < N; i++) cerr << A[i] << " "; cerr << endl;
#endif
}

bool isdone() {
	return L + R == N;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	scanf("%d%d%d", &N, &M, &C);
	for (I = 0; I < M; I++) {
		io();
		if (isdone()) break;
	}
	return 0;
}