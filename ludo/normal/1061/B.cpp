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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll N, H;
	cin >> N >> H;

	vi X(N);
	for (int &x : X) cin >> x;
	sort(all(X));

	ll sum = 0;
	REP(i, N) sum += X[i];

	// process X decreasingly
	ll keep = 0;
	for (int i = N; i--; ) {
		int nxtv = i == 0 ? 0 : X[i - 1];
		keep += max(1, X[i] - nxtv);
		if (i > 0 && X[i - 1] >= X[i] && X[i - 1] > 1)
			X[i - 1] = X[i] - 1; // decrease level
	}

	cout << (sum - keep) << endl;
	return 0;
}