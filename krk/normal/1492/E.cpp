#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 250005;

int n, m;
vector <vector <int> > B;
vector <ii> a;
map <int, int> L1[Maxn], R1[Maxn];
map <int, int> L2[Maxn], R2[Maxn];

bool Same(int col)
{
	for (int i = 0; i < B.size(); i++)
		if (B[i][col] != B[0][col]) return false;
	return true;
}

map <int, int> Get(int r1, int r2, int ign, bool plus)
{
	map <int, int> M;
	vector <int> seq;
	for (int j = 0; j < m; j++) if (j != ign)
		if (B[r1][j] != B[r2][j])
			seq.push_back(j);
	if (seq.empty()) { M[-1] = -1; return M; }
	if (seq.size() == 1)
		if (plus) { M[-1] = -1; return M; }
		else { M[seq[0]] = -1; M[m] = -1; return M; }
	if (seq.size() == 2)
		if (plus) {
			M[seq[0]] = -1;
			M[seq[1]] = -1;
			M[m] = -1;
			return M;
		} else {
			M[seq[0]] = B[r2][seq[0]];
			M[seq[1]] = B[r2][seq[1]];
			return M;
		}
	if (seq.size() == 3)
		if (plus) {
			M[seq[0]] = B[r2][seq[0]];
			M[seq[1]] = B[r2][seq[1]];
			M[seq[2]] = B[r2][seq[2]];
			return M;
		}
	return M;
}

map <int, int> Join(map <int, int> A, map <int, int> B)
{
	map <int, int> M;
	if (A.empty() || B.empty()) return M;
	if (A.begin()->first == -1) return B;
	if (B.begin()->first == -1) return A;
	auto ita = A.begin();
	auto itb = B.begin();
	while (ita != A.end() && itb != B.end())
		if (ita->first < itb->first) ita++;
		else if (ita->first > itb->first) itb++;
		else {
			if (ita->second == -1 || itb->second == -1 || ita->second == itb->second)
				M[ita->first] = ita->second == -1? itb->second: ita->second;
			ita++; itb++;
		}
	return M;
}

void Print(int r, map <int, int> &M)
{
	if (M.begin()->first != -1 && M.begin()->second != -1)
		B[r][M.begin()->first] = M.begin()->second;
	printf("Yes\n");
	for (int j = 0; j < m; j++)
		printf("%d%c", B[r][j], j + 1 < m? ' ': '\n');
}

int main()
{
	scanf("%d %d", &n, &m);
	B.resize(n);
	for (int i = 0; i < n; i++) {
		B[i].resize(m + 1);
		for (int j = 0; j < m; j++)
			scanf("%d", &B[i][j]);
	}
	int col = 0;
	while (col < m && Same(col)) col++;
	if (col >= m) {
		map <int, int> M;
		M[-1] = -1;
		Print(0, M);
		return 0;
	}
	for (int i = 0; i < n; i++)
		a.push_back(ii(B[i][col], i));
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		L1[i] = Get(a[0].second, a[i].second, col, false);
		L2[i] = Get(a[n - 1].second, a[i].second, col, false);
		if (i > 0) {
			L1[i] = Join(L1[i], L1[i - 1]);
			L2[i] = Join(L2[i], L2[i - 1]);
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		R1[i] = Get(a[0].second, a[i].second, col, false);
		R2[i] = Get(a[n - 1].second, a[i].second, col, false);
		if (i + 1 < n) {
			R1[i] = Join(R1[i], R1[i + 1]);
			R2[i] = Join(R2[i], R2[i + 1]);
		}
	}
	for (int i = 0, j; i < n; i = j) {
		j = i;
		map <int, int> M;
		M[-1] = -1;
		while (j < n && a[i].first == a[j].first) {
			M = Join(M, Get((i > 0? a[0].second: a[n - 1].second), a[j].second, col, true));
			j++;
		}
		if (i > 0) {
			M = Join(M, L1[i - 1]);
			if (j < n) M = Join(M, R1[j]);
			if (!M.empty()) { B[a[0].second][col] = a[i].first; Print(a[0].second, M); return 0; }
		} else {
			M = Join(M, R2[j]);
			if (!M.empty()) { B[a[n - 1].second][col] = a[i].first; Print(a[n - 1].second, M); return 0; }
		}
	}
	printf("No\n");
    return 0;
}