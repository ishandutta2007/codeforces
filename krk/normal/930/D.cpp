#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Inf = 1000000000;
const int nil = 200005;
const int Maxn = 400015;
const int Maxm = 2097152;

int n;
vector <ii> seq[2];
int mx[4][Maxm]; // U, L, R, D
ll res;

void Create(int v, int l, int r)
{
	for (int s = 0; s < 4; s++)
		mx[s][v] = -Inf;
	if (l < r) {
		int m = l + r >> 1;
		Create(2 * v, l, m); 
		Create(2 * v + 1, m + 1, r);
	}
}

void Update(int s, int v, int l, int r, int a, int b, int val)
{
	if (l == a && r == b) mx[s][v] = max(mx[s][v], val);
	else {
		int m = l + r >> 1;
		if (a <= m) Update(s, 2 * v, l, m, a, min(m, b), val);
		if (m + 1 <= b) Update(s, 2 * v + 1, m + 1, r, max(m + 1, a), b, val);
	}
}

int Get(int s, int v, int l, int r, int x)
{
	int res = mx[s][v];
	if (l < r) {
		int m = l + r >> 1;
		if (x <= m) res = max(res, Get(s, 2 * v, l, m, x));
		else res = max(res, Get(s, 2 * v + 1, m + 1, r, x));
	}
	return res;
}

void Solve(const vector <ii> &seq)
{
	Create(1, 0, Maxn);
	for (int i = 0; i < seq.size(); i++) {
		int a = seq[i].first + seq[i].second + nil;
		int b = seq[i].first - seq[i].second + nil;
		Update(0, 1, 0, Maxn, 0, a - 1, b);
		Update(1, 1, 0, Maxn, a, Maxn, b);
		Update(2, 1, 0, Maxn, 0, a - 1, -b);
		Update(3, 1, 0, Maxn, a, Maxn, -b);
	}
	for (int i = 0; i <= Maxn; i++) {
		int A = min(Get(0, 1, 0, Maxn, i), Get(1, 1, 0, Maxn, i));
		int B = -min(Get(2, 1, 0, Maxn, i), Get(3, 1, 0, Maxn, i));
		if (A > B) res += A - B;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b; scanf("%d %d", &a, &b);
		seq[(a + b) % 2 != 0].push_back(ii(a, b));
	}
	Solve(seq[0]);
	Solve(seq[1]);
	res /= 4ll;
	printf("%I64d\n", res);
	return 0;
}