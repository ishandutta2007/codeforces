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

const int maxn = 1000;

typedef pair<ll, ll> pt;
typedef pt frac;
typedef ll NUM;

pt operator+(pt a, pt b) { return pt(a.x + b.x, a.y + b.y); }
pt operator-(pt a, pt b) { return pt(a.x - b.x, a.y - b.y); }
NUM operator*(pt a, pt b) { return a.x * b.x + a.y * b.y; }
NUM operator^(pt a, pt b) { return a.x * b.y - a.y * b.x; }

int N;
pt A[maxn],B[maxn];

bool segmentIntersection(pt p, pt dp, pt q, pt dq, frac &t0)
{
	if (dp * dp == 0) swap(p, q), swap(dp, dq);
	if (dp * dp == 0) { t0 = frac(0, 1); return p == q; }
	pt dpq = q -p; NUM c = dp^dq, c0=dpq^dp,c1=dpq^dq;

	if (c == 0LL)
		return false; // assumption: no lines on the same line.
//	assert(c != 0LL);

	if (c < 0LL) c = -c, c0 = -c0, c1=-c1;
	t0 = frac(c1, c);
	return 0 <= min(c0, c1) && max(c0, c1) <= c;
}

ll gcd(ll a, ll b) { while (b) a %= b, swap(a, b); return a; }
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll ret = 0;

	cin >> N;
	REP(i, N) {
		cin >> A[i].x >> A[i].y >> B[i].x >> B[i].y;

		ll dx = abs(A[i].x - B[i].x);
		ll dy = abs(A[i].y - B[i].y);

		ll g = gcd(dx, dy);
		ret += g + 1;
	}

	// remove intersection points
	map< pt, set<int> > ints;
	REP(i, N) REP(j, N) {
		if (i == j) continue;

		frac perc;
		bool doIntersect = segmentIntersection(A[i], B[i] - A[i], A[j], B[j] - A[j], perc);
		if (!doIntersect) continue;

		pt dd = (B[i] - A[i]);
		dd.x *= perc.x;
		dd.y *= perc.x;

		if (dd.x % perc.y != 0 || dd.y % perc.y != 0)
			continue;

		dd.x /= perc.y;
		dd.y /= perc.y;

		pt intpt = A[i] + dd;

		ints[intpt].insert(i);
		ints[intpt].insert(j);
	}

	for (auto pr : ints) {
		/* cerr << pr.x.x << ", " << pr.x.y << ": ";
		for (int i : pr.y)
			cerr << i << ", ";
		cerr << endl; */
		ret -= pr.y.size() - 1;
	}

	cout << ret << endl;

	return 0;
}