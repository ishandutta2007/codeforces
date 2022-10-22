#include <cstdio>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;

const int Maxn = 205;
const int mod = 1000000007;
const ld seps = 1e-6l;

int n;
int x[Maxn], y[Maxn];
vector <int> neigh[Maxn];
int dp[Maxn][Maxn];

void Get(ll x1, ll y1, ll x2, ll y2, ll &A, ll &B, ll &C)
{
	A = y2 - y1;
	B = x1 - x2;
	C = A * x1 + B * y1;
}

bool onEdge(ll x1, ll y1, ll x2, ll y2, ll X, ll Y)
{
	ll ax = X - x1, ay = Y - y1;
	ll bx = x2 - x1, by = y2 - y1;
	if (ax * by - ay * bx) return false;
	if (ax * bx + ay * by < 0) return false;
	ax = X - x2, ay = Y - y2;
	bx = x1 - x2, by = y1 - y2;
	if (ax * bx + ay * by < 0) return false;
	return true;
}

bool Eq(ld x1, ld y1, ld x2, ld y2)
{
	return fabs(x1 - x2) < seps && fabs(y1 - y2) < seps;
}

bool getIntersection(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4)
{
	ll A1, B1, C1; Get(x1, y1, x2, y2, A1, B1, C1);
	ll A2, B2, C2; Get(x3, y3, x4, y4, A2, B2, C2);
	ll det = A1 * B2 - A2 * B1;
	if (det == 0) return false;
	ld X = (ld(B2) * C1 - ld(B1) * C2) / det;
	ld Y = (ld(A1) * C2 - ld(A2) * C1) / det;
	if (Eq(X, Y, x1, y1) || Eq(X, Y, x2, y2) || Eq(X, Y, x3, y3) || Eq(X, Y, x4, y4) ||
		X + seps < min(x1, x2) || max(x1, x2) + seps < X || Y + seps < min(y1, y2) || max(y1, y2) + seps < Y ||
		X + seps < min(x3, x4) || max(x3, x4) + seps < X || Y + seps < min(y3, y4) || max(y3, y4) + seps < Y)
		return false;
	return true;
}

int Calc(int v, int delt)
{
	if (delt <= 1) return 1;
	if (dp[v][delt] == -1) {
		int u = (v + delt) % n;
		int res = 0;
		int i = 0, j = 0;
		while (i < neigh[v].size() && j < neigh[u].size())
			if (neigh[v][i] < neigh[u][j]) i++;
			else if (neigh[u][j] < neigh[v][i]) j++;
			else {
				int m = neigh[v][i];
				int dist = m > v? m - v: m + n - v;
				if (dist < delt)
					res = (res + ll(Calc(v, dist)) * Calc(m, delt - dist) % mod) % mod;
				i++; j++;
			}
		dp[v][delt] = res;
	}
	return dp[v][delt];
}

bool includesPoints(int a, int b)
{
	int res = 0;
	for (int i = 0; i < n; i++)
		if (onEdge(x[a], y[a], x[b], y[b], x[i], y[i]))
			res++;
	return res >= 3;
}

bool isOutside(int a, int b)
{
	ll mx = (x[a] + x[b]) / 2, my = (y[a] + y[b]) / 2;
	for (int i = 0; i < n; i++)
		if (onEdge(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n], mx, my))
			return false;
	ll rx = 20000002 + rand(), ry = 20000005 + rand();
	int cur = 0;
	for (int i = 0; i < n; i++)
		if (getIntersection(mx, my, rx, ry, x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]))
			cur++;
	return cur % 2 == 0;
}

bool Intersects(int a, int b)
{
	for (int i = 0; i < n; i++)
		if (getIntersection(x[a], y[a], x[b], y[b], x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]))
			return true;
	return false;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		x[i] *= 2; y[i] *= 2;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			if (i != j && !includesPoints(i, j) && !isOutside(i, j) && !Intersects(i, j))
				neigh[i].push_back(j);
	fill((int*)dp, (int*)dp + Maxn * Maxn, -1);
	printf("%d\n", Calc(0, n - 1));
	return 0;
}