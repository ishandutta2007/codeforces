#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define rep(i,a,b) for (auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

ostream& operator<<(ostream &out, const ii &pr) { return out << '(' << pr.x << ',' << pr.y << ')'; }

const int maxn = 100;

int N, D, x[maxn];

void run()
{
	cin >> N >> D;
	REP(i, N) cin >> x[i];
	sort(x, x + N);

	int rem = 0;

	for (int l = 0; l < N; l++) {
		for (int r = l; r < N && x[r] - x[l] <= D; r++) {
			// [l, .., r] is valid range
			rem = max(rem, r - l + 1);
		}
	}
	cout << (N - rem) << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	run();

	return 0;
}