#include <bits/stdc++.h>
using namespace std;

const int Maxl = 26;
const int Maxn = 2005;

int n;
string A, B;
vector <int> V[Maxl];
int cur, seq[2][Maxn];
vector <int> res;

void Apply(int x)
{
	if (x == 0) return;
	res.push_back(x);
	int pnt = 0;
	for (int i = 1; i <= x; i++)
		seq[!cur][pnt++] = seq[cur][n - i];
	for (int i = 0; i < n - x; i++)
		seq[!cur][pnt++] = seq[cur][i];
	cur = !cur;
}

int Find(int val)
{
	for (int z = 0; z < n; z++)
		if (seq[cur][z] == val) return z;
	return -1;
}

void Solve(int val)
{
	int i = Find(n - 1), j = Find(val);
	if (i < j) {
		Apply(n - j - 1);
		Apply(n - Find(n - 1));
		Apply(n - Find(val + 1));
	} else {
		Apply(n - j - 1);
		Apply(1);
		Apply(n - Find(val + 1));
	}
}

int main()
{
	cin >> n;
	cin >> A;
	for (int i = 0; i < n; i++)
		V[A[i] - 'a'].push_back(i);
	cin >> B;
	for (int i = 0; i < n; i++) {
		int let = B[i] - 'a';
		if (V[let].empty()) { printf("-1\n"); return 0; }
		seq[cur][V[let].back()] = i; V[let].pop_back();
	}
	for (int i = n - 2; i >= 0; i--)
		Solve(i);
	Apply(n);
	printf("%d\n", int(res.size()));
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}