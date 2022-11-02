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

const int maxn = 50;
int N, M;
string G[maxn], moves;
ii S, E;

// x: row, y: col
bool isvalid(ii p) {
	return 0 <= p.x && p.x < N
		&& 0 <= p.y && p.y < M
		&& G[p.x][p.y] != '#';
}

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool tryDM(vi dm) {
	// cerr << endl << "PERM " << dm[0] << " " << dm[1] <<" " << dm[2] <<  " " << dm[3] << ": ";
	ii cur = S;
	for (char c : moves) {
		int idx = dm[c - '0'];
		cur.x += dx[idx];
		cur.y += dy[idx];
		if (!isvalid(cur)) return false;
		if (cur == E) return true;
		// cerr << cur.x << ", " << cur.y << ";  ";
	}
	// cerr << endl << "ENDED AT " << cur.x << ", " << cur.y << " VS " << E.x << ", " << E.y << endl;
	return cur == E;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	getline(cin, G[0]);
	for (int i = 0; i < N; i++) {
		getline(cin, G[i]);
		for (int j = 0; j < M; j++) {
			if (G[i][j] == 'S') S = ii(i, j);
			if (G[i][j] == 'E') E = ii(i, j);
		}
	}

	/*
	for (int i = 0; i  <N; i++) {
		for (int j = 0; j < M; j++) cerr << G[i][j];
		cerr << endl;
	}
	*/

	getline(cin, moves);

	vi dm(4);
	iota(all(dm), 0);
	int ret = 0;
	do {
		if (tryDM(dm)) ret++;
	} while (next_permutation(all(dm)));

	cout << ret << endl;
	return 0;
}