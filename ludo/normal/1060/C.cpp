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

const int maxn = 2e3;
const int INF = 1e9;

int N, M, A[maxn], B[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	REP(i, N) cin >> A[i];
	REP(i, M) cin >> B[i];

	vi mina(N + 1, INF);
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = i; j < N; j++) {
			sum += A[j];
			mina[j - i + 1] = min(mina[j-i+1], sum);
		}
	}

	vi minb(M + 1, INF);
	for (int i = 0; i < M; i++) {
		int sum = 0;
		for (int j = i; j < M; j++) {
			sum += B[j];
			minb[j - i + 1] = min(minb[j-i+1], sum);
		}
	}

	// REP(i, N + 1) cerr << i << ": " << mina[i] << endl;
	// REP(i, M + 1) cerr << i << ": " << minb[i] << endl;

	ll X;
	cin >> X;
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (1LL * mina[i] * minb[j] <= X)
				ret = max(ret, i * j);
		}
	}
	cout << ret << endl;
	return 0;
}