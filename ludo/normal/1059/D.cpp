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

const int maxn = 1e5;
const ld EPS = 1e-10;


int N, X[maxn], Y[maxn];

bool test(ld R)
{
	ld leftX = -1e7;
	ld rightX = 1e7;
	REP(i, N) {
		ld det = Y[i] * (R + R - Y[i]);
		det = sqrt(det);
		leftX = max(leftX, X[i] - det);
		rightX = min(rightX, X[i] + det);

		// cerr << leftX << " " << rightX << endl;
		if (leftX > rightX) return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
(cout<< fixed).precision(15);

	cin >> N;
	REP(i, N) cin >> X[i] >> Y[i];

	int npos = 0, nneg = 0, maxy = 0;
	REP(i, N) {
		if (Y[i] < 0) Y[i] = -Y[i], nneg++;
		else npos++;
		maxy = max(maxy, Y[i]);
	}

	if (npos > 0 && nneg > 0) {
		cout << "-1" << endl;
		return 0;
	}

	// binary search
	ld lo = maxy * 0.5, hi = 1e15;
	while (hi - lo > EPS && hi / lo >= 1.0 + EPS) {
		// cerr << lo << " " << hi << "\t";
		ld mi = (hi + lo) * 0.5;
		bool result = test(mi);
		// cerr << mi << ": " << result << endl;
		if (result) hi = mi;
		else lo = mi;
	}

	cout << ((lo + hi) * 0.5) << endl;
	return 0;
}