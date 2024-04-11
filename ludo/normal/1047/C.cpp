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

const int maxn = 3e5;
const int maxnum = 1.5e7 + 10;

int A[maxn];

int lp[maxnum] = {};

int gcd(int a, int b) { while (b) a %= b, swap(a, b); return a; }

int main()
{
	srand(3141576);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 2; i * i < maxnum; i++) {
		if (lp[i] != 0) continue;
		lp[i] = i;
		for (int j = i * i; j < maxnum; j += i) {
			if (!lp[j]) lp[j] = i;
		}
	}

	for (int i = 2; i < maxnum; i++) if (!lp[i]) lp[i] = i;

	int N, g = 0;
	cin >> N;
	REP(i, N) {
		cin >> A[i];
		g = gcd(g, A[i]);
	}

	if (g > 1) {
		REP(i, N) A[i] /= g;
	}

	int ones = 0;
	for (int i = 0; i < N; ) {
		if (A[i] != 1) {
			i++;
		} else {
			swap(A[i], A[--N]);
			ones++;
		}
	}

	if (N == 0) {
		cout << "-1" << endl;
		return 0;
	}

	// we can remove at least $N-1$ numbers.

	unordered_map<int, int> pcount;
	REP(i, N) {
		int lastp = -1;
		for (int j = A[i]; j > 1; j /= lp[j]) {
			if (lp[j] != lastp) {
				lastp = lp[j];
				pcount[lastp]++;
			}
		}
	}

	int ret = 1;
	for (ii pr : pcount) {
		ret = max(ret, pr.y);
	}

	// the GCD set is of size `ret'.
	// remove thus, ones + (N - ret)
	cout << (ones + (N - ret)) << endl;
	return 0;
}