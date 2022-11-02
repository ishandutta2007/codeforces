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

// 0: E, 1: T, 2: F
bool found[3][256] = {};
string sol[3][256];

inline int maskNot(const int x) {
	return (~x) & 255;
}

// a: alt
// b: cur
bool isbetter(const string &a, const string &b) {
	if (a.size() != b.size()) return a.size() < b.size();
	return a < b;
}

struct cmp_ii {
	bool operator() (const ii &a, const ii &b) const {
		if (sol[a.x][a.y].size() != sol[b.x][b.y].size())
			return sol[a.x][a.y].size() < sol[b.x][b.y].size();
		return sol[a.x][a.y] < sol[b.x][b.y];
	}
};

void try_improve(set<ii, cmp_ii> &pq, int x, int y, const string &S) {
	if (!found[x][y] || isbetter(S, sol[x][y])) {
		found[x][y] = true;
		sol[x][y] = S;
		pq.emplace(x, y);
	}
}

void precalculate()
{
	found[2][15] = true; sol[2][15] = "x";
	found[2][51] = true; sol[2][51] = "y";
	found[2][85] = true; sol[2][85] = "z";

	set<ii, cmp_ii> pq;
	pq.emplace(2, 15);
	pq.emplace(2, 51);
	pq.emplace(2, 85);

	while (!pq.empty()) {
		ii cur = *pq.begin();
		pq.erase(pq.begin());

		assert(found[cur.x][cur.y]);

		// try to improve others which might use this one.
		if (cur.x == 0) {
			// E
			REP(i, 256) {
				int j = i | cur.y;
				if (!found[1][i]) continue;
				// improve E[j] made by E[cur.y] | T[i]
				string alt = sol[0][cur.y] + "|" + sol[1][i];
				try_improve(pq, 0, j, alt);
			}
			// improve F[cur.y] with (E[cur.y])
			string altF = "(" + sol[0][cur.y] + ")";
			try_improve(pq, 2, cur.y, altF);
		} else if (cur.x == 1) {
			// T
			REP(i, 256) {
				// improve T[j] made by T[cur.y] & F[i]
				int j = i & cur.y;
				if (!found[2][i]) continue;
				string alt = sol[1][cur.y] + "&" + sol[2][i];
				try_improve(pq, 1, j, alt);
			}
			REP(i, 256) {
				int j = i | cur.y;
				if (!found[0][i]) continue;
				// improve E[j] made by E[i] | T[cur.y]
				string alt = sol[0][i] + "|" + sol[1][cur.y];
				if (!found[0][j] || isbetter(alt, sol[0][j])) {
					found[0][j] = true;
					sol[0][j] = alt;
					pq.emplace(0, j);
				}
			}
			// improve E[cur.y] with T[cur.y]
			try_improve(pq, 0, cur.y, sol[1][cur.y]);
		} else if (cur.x == 2) {
			// F
			REP(i, 256) {
				// improve T[j] with T[i] & F[cur.y]
				int j = i & cur.y;
				if (!found[1][i]) continue;
				string alt = sol[1][i] + "&" + sol[2][cur.y];
				if (!found[1][j] || isbetter(alt, sol[1][j])) {
					found[1][j] = true;
					sol[1][j] = alt;
					pq.emplace(1, j);
				}
			}

			// improve F[~cur.y] with ! F[cur.y]
			int altY = maskNot(cur.y);
			string altF = "!" + sol[2][cur.y];
			if (!found[2][altY] || isbetter(altF, sol[2][altY])) {
				found[2][altY] = true;
				sol[2][altY] = altF;
				pq.emplace(2, altY);
			}

			// improve T with F
			try_improve(pq, 1, cur.y, sol[2][cur.y]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	precalculate();

	REP(i, 256) assert(found[0][i]);

	int N;
	cin >> N;
	while (N--) {
		string line;
		cin >> line;

		int num = 0;
		for (int i = 0; i < 8; i++) {
			if (line[i] == '1') num |= (1 << (7 - i));
		}
		cout << sol[0][num] << endl;
	}
	return 0;
}