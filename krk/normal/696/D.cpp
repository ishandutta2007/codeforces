#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 205;
const ll Inf = 4000000000000000000ll;

struct matrix {
	ll m[Maxn][Maxn];
	matrix() { fill((ll*)m, (ll*)m + Maxn * Maxn, -Inf); }
	matrix operator*(const matrix &b) const {
		matrix c;
		for (int i = 0; i < Maxn; i++)
			for (int j = 0; j < Maxn; j++)
				for (int k = 0; k < Maxn; k++)
					c.m[i][j] = max(c.m[i][j], m[i][k] + b.m[k][j]);
		return c;
	}
};

int n;
ll l;
int a[Maxn], nw[Maxn];
string s[Maxn];
int st[Maxn];
matrix A;

int main()
{
	scanf("%d %I64d", &n, &l);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int cur = 0;
	for (int i = 0; i < n; i++) {
		st[i] = cur; 
		cin >> s[i];
		cur += s[i].length();
		nw[cur - 1] = a[i];
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) if (i != j)
			for (int l = 0; l + s[j].size() <= s[i].size(); l++)
				if (s[i].substr(l, s[j].size()) == s[j])
					nw[st[i] + l + s[j].size() - 1] += a[j];
	for (int i = 0; i < n; i++)
		A.m[Maxn - 1][st[i]] = nw[st[i]];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j + 1 < s[i].length(); j++)
			A.m[st[i] + j][st[i] + j + 1] = nw[st[i] + j + 1];
		for (int j = 0; j < n; j++)
			for (int l = 0; l < s[i].length() && l < s[j].length(); l++)
				if (s[i].substr(s[i].length() - l) == s[j].substr(0, l))
					A.m[st[i] + s[i].length() - 1][st[j] + l] = nw[st[j] + l];
	}
	bool was = false;
	matrix R;
	while (l) {
		if (l & 1)
			if (was) R = R * A;
			else { R = A; was = true; }
		l >>= 1; A = A * A;
	}
	ll mx = -Inf;
	for (int i = 0; i < cur; i++)
		mx = max(mx, R.m[Maxn - 1][i]);
	printf("%I64d\n", mx);
	return 0;
}