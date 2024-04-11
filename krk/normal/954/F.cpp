#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ii> llii;

const int Maxr = 3;
const int mod = 1000000007;

struct matrix {
	int m[Maxr][Maxr];
	matrix(int diag = 0) {
		for (int i = 0; i < Maxr; i++)
			for (int j = 0; j < Maxr; j++)
				m[i][j] = (i == j) * diag;
	}
	matrix operator *(const matrix &b) const {
		matrix c;
		for (int i = 0; i < Maxr; i++)
			for (int j = 0; j < Maxr; j++)
				for (int l = 0; l < Maxr; l++)
					c.m[i][j] = (c.m[i][j] + ll(m[i][l]) * b.m[l][j]) % mod;
		return c;
	}
};

int st[Maxr];
int n;
ll m;
vector <llii> seq;
int cur[Maxr], ncur[Maxr];

void Update(ll el)
{
	if (el == 0) return;
	matrix R(1), A;
	if (!st[0]) A.m[0][0] = A.m[0][1] = 1;
	if (!st[1]) A.m[1][0] = A.m[1][1] = A.m[1][2] = 1;
	if (!st[2]) A.m[2][1] = A.m[2][2] = 1;
	while (el) {
		if (el & 1) R = R * A;
		el >>= 1; A = A * A;
	}
	for (int i = 0; i < Maxr; i++) {
		ncur[i] = 0;
		for (int j = 0; j < Maxr; j++)
			ncur[i] = (ncur[i] + ll(R.m[i][j]) * cur[j]) % mod;
	}
	for (int i = 0; i < Maxr; i++)
		cur[i] = ncur[i];
}

int main()
{
	scanf("%d %I64d", &n, &m);
	ll lst = 1;
	cur[1] = 1;
	for (int i = 0; i < n; i++) {
		int a; ll l, r; scanf("%d %I64d %I64d", &a, &l, &r); a--;
		seq.push_back(llii(l, ii(a, 1)));
		seq.push_back(llii(r + 1, ii(a, -1)));
	}
	sort(seq.begin(), seq.end());
	for (int i = 0; i < seq.size(); i++) {
		Update(seq[i].first - 1 - lst); lst = seq[i].first - 1;
		st[seq[i].second.first] += seq[i].second.second;
	}
	Update(m - lst);
	printf("%d\n", cur[1]);
	return 0;
}