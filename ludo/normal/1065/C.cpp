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

const int maxn = 2e5;

int N, K, A[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	assert(N <= K);
	REP(i, N) cin >> A[i];
	sort(A, A + N);

	vii grps;
	int cursz = 1, curval = A[0];
	for (int i = 1; i <= N; i++) {
		if (i == N || A[i] != A[i - 1]) {
			grps.eb(curval, cursz);
			curval = A[i];
			cursz = 0;
		}
		cursz++;
	}

	ll ret = 0;
	int curh = grps.back().x;
	int curn = grps.back().y;
	grps.pop_back();
	while (!grps.empty() && curh > grps.front().x) {
		// lower by some amount.

		int used = 0;
		while (!grps.empty() && used + (curh == grps.back().x ? grps.back().y : 0) + curn <= K) {
			if (curh == grps.back().x) {
				curn += grps.back().y;
				grps.pop_back();
			}
			used += curn;
			curh--;
		}
		// assert(used <= K);
		// cerr << "DECREASE TO HEIGHT: " << curh << " using " << used << endl;
		ret++;
	}
	cout << ret << endl;
	return 0;
}