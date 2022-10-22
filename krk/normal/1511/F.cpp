#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <string, string> ss;
typedef vector <vector <int> > matrix;

const int mod = 998244353;

int n, m;
set <string> full, part;
map <ss, int> M;
vector <ii> add;
matrix R, A;

matrix Mult(matrix &A, const matrix &B)
{
	int n = A.size();
	matrix C;
	C.resize(n);
	for (int i = 0; i < n; i++)
		C[i].resize(n, 0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				C[i][j] = (C[i][j] + ll(A[i][k]) * B[k][j]) % mod;
	return C;
}

int main()
{
	cin >> n >> m;
	part.insert("");
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		full.insert(s);
		for (int j = 1; j <= s.length(); j++)
			part.insert(s.substr(0, j));
	}
	vector <ss> Q;
	M[ss("", "")] = 0;
	Q.push_back(ss("", ""));
	for (int i = 0; i < Q.size(); i++) {
		for (int ch = 'a'; ch <= 'z'; ch++) {
			string A = Q[i].first + string(1, ch);
			string B = Q[i].second + string(1, ch);
			if (A > B) swap(A, B);
			if (part.count(A) && part.count(B)) {
				if (!M.count(ss(A, B))) {
					M[ss(A, B)] = Q.size();
					Q.push_back(ss(A, B));
				}
				add.push_back(ii(i, M[ss(A, B)]));
				if (full.count(A)) {
					if (!M.count(ss("", B))) {
						M[ss("", B)] = Q.size();
						Q.push_back(ss("", B));
					}
					add.push_back(ii(i, M[ss("", B)]));
				}
				if (full.count(B)) {
					if (!M.count(ss("", A))) {
						M[ss("", A)] = Q.size();
						Q.push_back(ss("", A));
					}
					add.push_back(ii(i, M[ss("", A)]));
				}
				if (full.count(A) && full.count(B))
					add.push_back(ii(i, 0));
			}
		}
	}
	int n = Q.size();
	matrix R(n), A(n);
	for (int i = 0; i < n; i++) {
		R[i].resize(n, 0);
		A[i].resize(n, 0);
		R[i][i] = 1;
	}
	for (auto p: add)
		A[p.second][p.first]++;
	while (m) {
		if (m & 1) R = Mult(R, A);
		m >>= 1; A = Mult(A, A);
	}
	printf("%d\n", R[0][0]);
    return 0;
}