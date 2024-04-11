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

const int MAX = 201;
const int IMP = -100;

// [ awins ][ bwins ][ ptsa ][ ptsb ] -> best score
bool mem[4][4][MAX][MAX] = {};
int bsc[4][4][MAX][MAX]; // (or -100 if impossible, or 3/-3 when done)
ii tk[4][4][MAX][MAX]; // (take a, take b)

int rec(int wa, int wb, int a, int b)
{
	// someone won
	if (wa == 3 || wb == 3) {
		return a == 0 && b == 0 ? wa-wb : IMP;
	}

	if (wa + wb == 4) {
		// base case.
		if (max(a, b) < 15) return IMP;
		if (max(a, b) == 15 && abs(a - b) < 2) return IMP;
		if (max(a, b) > 15 && abs(a - b) != 2) return IMP;

		tk[wa][wb][a][b] = ii(a, b);
		return (wa + (a > b)) - (wb + (b > a));
	}

	if (mem[wa][wb][a][b]) return bsc[wa][wb][a][b];

	// no option found yet
	int &cs = bsc[wa][wb][a][b];

	cs = IMP;

	if (a >= 25) {
		int sca = 25;
		for (int scb = 0; scb <= sca - 2 && scb <= b; scb++) {
			int alt = rec(wa + 1, wb, a - sca, b - scb);
			if (alt > cs) cs = alt, tk[wa][wb][a][b] = ii(sca, scb);
		}
		int scb = sca - 2;
		while (++sca <= a && ++scb <= b) {
			int alt = rec(wa + 1, wb, a - sca, b - scb);
			if (alt > cs) cs = alt, tk[wa][wb][a][b] = ii(sca, scb);
		}
	}
	if (b >= 25) {
		int scb = 25;
		for (int sca = 0; sca <= scb - 2 && sca <= a; sca++) {
			int blt = rec(wa, wb + 1, a - sca, b - scb);
			if (blt > cs) cs = blt, tk[wa][wb][a][b] = ii(sca, scb);
		}
		int sca = scb - 2;
		while (++scb <= b && ++sca <= a) {
			int blt = rec(wa, wb + 1, a - sca, b - scb);
			if (blt > cs) cs = blt, tk[wa][wb][a][b] = ii(sca, scb);
		}
	}

	mem[wa][wb][a][b] = true;
	return cs;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ntc;
	cin >> ntc;
	while (ntc--) {
		int a, b;
		cin >> a >> b;
		int score = rec(0, 0, a, b);
		if (score == IMP) { printf("Impossible\n"); continue; }
		// recurse
		vii matches;
		int wa = 0, wb = 0;
		while (a != 0 || b != 0) {
			ii pr = tk[wa][wb][a][b];
			wa += pr.x > pr.y;
			wb += pr.y > pr.x;
			assert(abs(pr.x - pr.y) >= 2); // sign. diff.
			a -= pr.x;
			b -= pr.y;
			matches.pb(pr);
		}
		printf("%d:%d\n", wa, wb);
		int lst = matches.size();
		for (ii pr : matches) {
			printf("%d:%d%c", pr.x, pr.y, " \n"[--lst == 0]);
		}
	}
	return 0;
}