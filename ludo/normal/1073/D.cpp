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

const int maxn  = 2e5 + 10;

ll N, T, A[maxn], BIT[maxn] = {};

void add(int i, ll v)
{
	while (i < maxn) BIT[i] += v, i += i & -i;
}

ll query(int i)
{
	ll r = 0;
	while (i > 0) r += BIT[i], i -= i & -i;
	return r;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> T;
	REP(i, N) {
		cin >> A[i];
		add(i + 1, A[i]);
	}

	ll ret = 0;
	for (int i = 0; i < N; i++) {
		ll sum = query(N);

		ret += (T / sum) * (N - i);
		T %= sum;

		int lo = 0, hi = N;
		while (hi - lo > 1) {
			int mi = (lo + hi) / 2;
			if (query(mi) <= T) lo = mi; else hi = mi;
		}

		// cerr << i << ": blocked by " << lo << " " << hi << endl;
		add(hi, -A[lo]);
		sum -= A[lo];
	}

	cout << ret << endl;
	return 0;
}