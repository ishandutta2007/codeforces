
#include <iostream>
#include <bitset>
#include <vector>
#include <cassert>
#include <numeric>
#include <map>

using namespace std;

#define sz(x) (int) (x).size()
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

const int N = 1000;

// book code from KACTL notebook

typedef bitset<2 * N> bs;

int solveLinear(vector<bs>& A, vi& b, bs& x, int m) {
	int n = sz(A), rank = 0, br;
	assert(m <= sz(x));
	vi col(m); iota(all(col), 0);
	rep(i,0,n) {
		for (br=i; br<n; ++br) if (A[br].any()) break;
		if (br == n) {
			rep(j,i,n) if(b[j]) return -1;
			break;
		}
		int bc = (int)A[br]._Find_next(i-1);
		swap(A[i], A[br]);
		swap(b[i], b[br]);
		swap(col[i], col[bc]);
		rep(j,0,n) if (A[j][i] != A[j][bc]) {
			A[j].flip(i); A[j].flip(bc);
		}
		rep(j,i+1,n) if (A[j][i]) {
			b[j] ^= b[i];
			A[j] ^= A[i];
		}
		rank++;
	}

	x = bs();
	for (int i = rank; i--;) {
		if (!b[i]) continue;
		x[col[i]] = 1;
		rep(j,0,i) b[j] ^= A[j][i];
	}
	return rank; // (multiple solutions if rank < m)
}

// 2 x 2 matrix representing how a color is changed after swap operations
struct mat {
	bool A[2][2];
	mat() {
		A[0][0] = A[1][1] = 1;
		A[0][1] = A[1][0] = 0;
	}
	mat(bool a00, bool a01, bool a10, bool a11) {
		A[0][0] = a00;
		A[0][1] = a01;
		A[1][0] = a10;
		A[1][1] = a11;
	}
	mat operator*(const mat &o) const {
		return mat((A[0][0] && o.A[0][0]) ^ (A[0][1] && o.A[1][0]),
				   (A[0][0] && o.A[0][1]) ^ (A[0][1] && o.A[1][1]),
				   (A[1][0] && o.A[0][0]) ^ (A[1][1] && o.A[1][0]),
				   (A[1][0] && o.A[0][1]) ^ (A[1][1] && o.A[1][1]));
	}
};

vector<bs> A;
vi b;
bs x;
int n, k, m, idx;
char c;

map<char, int> mp = {{'W', 0}, {'R', 1}, {'Y', 2}, {'B', 3}};
char arr[4] = {'.', 'R', 'Y', 'B'};
map<string, mat> opmap = {{"RY", {0, 1, 1, 0}}, {"RB", {1, 0, 1, 1}}, {"YB", {1, 1, 0, 1}}};
mat cellmat[N];
string op;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    A = vector<bs>(2 * k);
    b = vector<int>(2 * k);
	int r = 0;
    for(int i = 0; i < k; i++) {
		cin >> op >> m;
		if(op == "mix") {
			for(int j = 0; j < m; j++) {
				cin >> idx;
				idx--;
				for(int x : {0, 1}) {
					for(int y : {0, 1}) {
						A[2 * r + x][2 * idx + y] = cellmat[idx].A[x][y];
					}
				}
			}
			cin >> c;
			b[2 * r] = mp[c] % 2;
			b[2 * r + 1] = mp[c] / 2;
			r++;
		}else {
			mat mm = opmap[op];
			for(int j = 0; j < m; j++) {
				cin >> idx;
				idx--;
				cellmat[idx] = mm * cellmat[idx];
			}
		}
    }
	A.resize(2 * r);
	b.resize(2 * r);
    int rank = solveLinear(A, b, x, 2 * n);
    if(rank == -1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for(int i = 0; i < 2 * n; i += 2) {
        cout << arr[x[i + 1] * 2 + x[i]];
    }
    cout << '\n';
}