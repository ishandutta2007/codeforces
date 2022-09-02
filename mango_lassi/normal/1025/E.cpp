#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <assert.h>
using namespace std;

const int N = 50;
const int M = 50;
int inds[N][N];
int cx[M];
int cy[M];
int tx[M];
int ty[M];
int apps[N]; // appearances on the given horizontal line

vector<vector<int>> moves;

bool makeMove(int i, int dx, int dy, int n) {
	int tix = cx[i] + dx;
	int tiy = cy[i] + dy;
	if (tix < 0 || tix >= n || tiy < 0 || tiy >= n) return false;
	if (inds[tix][tiy] != -1) return false;


	vector<int> mv (4);
	inds[cx[i]][cy[i]] = -1;
	mv[0] = cx[i];
	mv[1] = cy[i];
	cx[i] = tix;
	cy[i] = tiy;
	mv[2] = tix;
	mv[3] = tiy;
	inds[tix][tiy] = i;
	moves.push_back(mv);
	return true;
}

void printState(int n) {
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			if (inds[x][y] == -1) {
				cout << "-";
			} else {
				int i = inds[x][y];
				assert(cx[i] == x && cy[i] == y);
				cout << i % 10;
			}
		}
		cout << '\n';
	}
}

int main() {
	// 1. Every cube goes to a unique y-coordinate (n*n moves)
	// 2. Every cube goes to the correct column (n*n moves)
	// 3. At least one column is empty or this is trivial (n*n) moves (and step 4 doesn't happen)
	// 4. Using the empty one, solve its left side, then solve its right side (2*n*(n+1) moves)

	int n, m;
	cin >> n >> m;
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y) {
			inds[x][y] = -1;
		}
	}
	for (int i = 0; i < m; ++i) {
		cin >> cx[i] >> cy[i];
		--cx[i]; --cy[i];
		assert(inds[cx[i]][cy[i]] == -1);
		inds[cx[i]][cy[i]] = i;
		++apps[cy[i]];
	}
	for (int i = 0; i < m; ++i) {
		cin >> tx[i] >> ty[i];
		--tx[i]; --ty[i];
	}
	
	// 1. Every cube goes to a unique y-coordinate (n*n moves)
	for (int x = 0; x < n; ++x) {
		int cou = 0;
		vector<int> targets;
		for (int y = 0; y < n; ++y) {
			if (inds[x][y] == -1) continue;
			++cou;
			--apps[y];
		}
		for (int y = 0; (targets.size() < cou) && (y < n); ++y) {
			if (apps[y] == 0) targets.push_back(y);
		}

		int j = 0;
		for (int y = 0; y < n; ++y) {
			int i = inds[x][y];
			if (i == -1) continue;
			if (targets[j] <= y) {
				while(cy[i] != targets[j]) makeMove(i, 0, -1, n);
			}
			++j;
		}
		j = cou - 1;
		for (int y = n-1; y >= 0; --y) {
			int i = inds[x][y];
			if (i == -1) continue;
			if (targets[j] >= y) {
				while(cy[i] != targets[j]) makeMove(i, 0, 1, n);
			}
			--j;
		}
		for (int y = 0; y < n; ++y) {
			if (inds[x][y] != -1) ++apps[y];
		}
	}
	
	// 2. Every cube goes to the correct column (n*n) moves
	for (int i = 0; i < n; ++i) apps[i] = 0;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			int i = inds[x][y];
			if (i == -1) continue;
			int dx = 0;
			if (tx[i] < x) dx = -1;
			else dx = 1;
			while(cx[i] != tx[i]) makeMove(i, dx, 0, n);
		}
	}
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y) {
			if (inds[x][y] != -1) ++apps[x];
		}
	}

	// 3. At least one column is empty or this is trivial, and solvable in n*n operations.
	int empt = -1;
	for (int x = 0; x < n; ++x) {
		if (apps[x] == 0) {
			empt = x;
			break;
		}
	}
	if (empt == -1) {
		// 3. Trivial
		for (int x = 0; x < n; ++x) {
			for (int y = 0; y < n; ++y) {
				int i = inds[x][y];
				if (i == -1) continue;
				int dy = 0;
				if (ty[i] < y) dy = -1;
				else dy = 1;
				while(cy[i] != ty[i]) makeMove(i, 0, dy, n);
			}
		}
	} else {
		// 4. Using the empty one, solve its left side, then solve its right side (2*n*(n+1) moves)
		// left side
		for (int x = empt - 1; x >= 0; --x) {
			// Sort this column into the column on its right side into the correct order in 2*n*(n+1) moves.
			vector<pair<int, int>> targets;
			for (int y = 0; y < n; ++y) {
				int i = inds[x][y];
				if (i == -1) continue;
				targets.push_back({-ty[i], i});
				while(true) {
					if (! makeMove(i, 0, -1, n)) break;
				}
			}
			sort(targets.begin(), targets.end());
			for (auto it : targets) {
				int i = it.second;
				int start = cy[i];				
				makeMove(i, 1, 0, n);
				while(cy[i] != ty[i]) makeMove(i, 0, 1, n);

				// Move everything up
				for (int y = start+1; y < n; ++y) {
					int j = inds[x][y];
					if (j == -1) break;
					makeMove(j, 0, -1, n);
				}
			}
		}
		for (int x = 1; x <= empt; ++x) {
			for (int y = 0; y < n; ++y) {
				int i = inds[x][y];
				if (i == -1) continue;
				makeMove(i, -1, 0, n);
			}
		}
		// Right side
		for (int x = empt + 1; x < n; ++x) {
			// Sort this column into the column on its right side into the correct order in 2*n*(n+1) moves.
			vector<pair<int, int>> targets;
			for (int y = 0; y < n; ++y) {
				int i = inds[x][y];
				if (i == -1) continue;
				targets.push_back({-ty[i], i});
				while(true) {
					if (! makeMove(i, 0, -1, n)) break;
				}
			}
			sort(targets.begin(), targets.end());
			for (auto it : targets) {
				int i = it.second;
				int start = cy[i];
				makeMove(i, -1, 0, n);
				while(cy[i] != ty[i]) makeMove(i, 0, 1, n);
				
				// Move everything up
				for (int y = start+1; y < n; ++y) {
					int j = inds[x][y];
					if (j == -1) break;
					makeMove(j, 0, -1, n);
				}

			}
		}
		for (int x = n-2; x >= empt; --x) {
			for (int y = 0; y < n; ++y) {
				int i = inds[x][y];
				if (i == -1) continue;
				makeMove(i, 1, 0, n);
			}
		}
	}
	
	// 5. Print answer
	cout << moves.size() << '\n';
	for (int i = 0; i < moves.size(); ++i) {
		for (auto j : moves[i]) cout << (j+1) << ' '; cout << '\n';
	}
	
}