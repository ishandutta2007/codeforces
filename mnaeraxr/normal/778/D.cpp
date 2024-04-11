#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

char t(char c){
	if (c == 'L') return 'U';
	if (c == 'U') return 'L';
	if (c == 'R') return 'D';
	if (c == 'D') return 'R';
}

vector<string> transpose(vector<string> A){
	int n = (int)A.size(), m = (int)A[0].length();
	string s = "";
	for (int i = 0; i < n; ++i) s += '0';
	vector<string> T(m, s);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j){
			T[j][i] = t( A[i][j] );
		}

	return T;
}

void apply(vector<string> &A, pii p){
	if (A[p.first][p.second] == 'U'){
		A[p.first][p.second] = 'L';
		A[p.first + 1][p.second] = 'L';
		A[p.first][p.second + 1] = 'R';
		A[p.first + 1][p.second + 1] = 'R';
	}
	else{
		A[p.first][p.second] = 'U';
		A[p.first][p.second + 1] = 'U';
		A[p.first + 1][p.second] = 'D';
		A[p.first + 1][p.second + 1] = 'D';
	}
}

vector<pii> solve(vector<string> &A){
	int n = (int)A.size(), m = (int)A[0].length();

	vector<pii> seq;

	for (int i = 0; i < n; i += 2){
		for (int j = 0; j < m; ++j){
			if (A[i][j] == 'U') continue;

			int x = i, y = j;
			int c = 0;

			vector<pii> cur(1, pii(x, y));

			while (true){
				if (c == 0){
					x++;
					if (A[x][y] == 'L')
						break;
				}
				else{
					y++;
					if (A[x][y] == 'U')
						break;
				}

				cur.push_back(pii(x, y));

				c ^= 1;
			}

			reverse(cur.begin(), cur.end());

			for (auto p : cur){
				seq.push_back(p);
				apply(A, p);
			}
		}
	}

	return seq;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifdef MARX
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;

	vector<string> A(n), B(n);

	for (int i = 0; i < n; ++i)
		cin >> A[i];

	for (int i = 0; i < n; ++i)
		cin >> B[i];

	bool t = false;

	if (n & 1){
		t = true;
		A = transpose(A);
		B = transpose(B);
	}

	vector<pii> seqA = solve(A);
	vector<pii> seqB = solve(B);

	reverse(seqB.begin(), seqB.end());

	cout << seqA.size() + seqB.size() << endl;

	for (auto p : seqA){
		if (t) swap(p.first, p.second);
		cout << p.first + 1 << " " << p.second + 1 << endl;
	}

	for (auto p : seqB){
		if (t) swap(p.first, p.second);
		cout << p.first + 1 << " " << p.second + 1 << endl;
	}

	return 0;
}