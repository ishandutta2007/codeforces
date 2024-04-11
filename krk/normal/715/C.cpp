#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 100005;

int n, M;
int pw[Maxn], inv[Maxn];
vector <ii> neigh[Maxn];
int L[Maxn], P[Maxn], H;
int A[Maxn], B[Maxn];
map <int, int> X[Maxn], Y[Maxn];
int par[Maxn];
ll res;

int Get(map <int, int> &M, int val)
{
	map <int, int>::iterator it = M.find(val);
	return it == M.end()? 0: it->second;
}

int getPower(int p) { return p >= 0? pw[p]: inv[-p]; }

void Merge(int a, int b, int L)
{
	for (map <int, int>::iterator it = X[par[b]].begin(); it != X[par[b]].end(); it++) {
		int rX = (it->first + A[par[b]]) % M;
		int rY = (M - ll(rX) * getPower(H - 2 * L) % M) % M;
		rY = (rY - B[par[a]] + M) % M;
		res += ll(it->second) * Get(Y[par[a]], rY);
	}
	for (map <int, int>::iterator it = Y[par[b]].begin(); it != Y[par[b]].end(); it++) {
		int rY = (it->first + B[par[b]]) % M;
		int rX = (M - ll(rY) * getPower(2 * L - H) % M) % M;
		rX = (rX - A[par[a]] + M) % M;
		res += ll(it->second) * Get(X[par[a]], rX);
		Y[par[a]][(rY - B[par[a]] + M) % M] += it->second;
	}
	Y[par[b]].clear();
	for (map <int, int>::iterator it = X[par[b]].begin(); it != X[par[b]].end(); it++) {
		int rX = (it->first + A[par[b]]) % M;
		X[par[a]][(rX - A[par[a]] + M) % M] += it->second;
	}
	X[par[b]].clear();
	par[b] = par[a];
}

void Traverse2(int v)
{
	par[v] = v; X[par[v]][0]++; Y[par[v]][0]++;
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (u.first == P[v]) continue;
		Traverse2(u.first);
		A[par[u.first]] = (A[par[u.first]] + ll(pw[L[v]]) * u.second) % M;
		B[par[u.first]] = (B[par[u.first]] + ll(pw[H - L[v] - 1]) * u.second) % M;
		if (max(X[par[v]].size(), Y[par[v]].size()) >= max(X[par[u.first]].size(), Y[par[u.first]].size()))
			Merge(v, u.first, L[v]);
		else Merge(u.first, v, L[v]);
	}
}

void Traverse1(int v)
{
	H = max(H, L[v]);
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (P[v] == u.first) continue;
		P[u.first] = v; L[u.first] = L[v] + 1;
		Traverse1(u.first);
	}
}

void gcd(int a, ll &x, int b, ll &y)
{
	if (a == 0) { x = 0; y = 1; }
	else {
		ll xx, yy; gcd(b % a, xx, a, yy);
		x = yy - b / a * xx; y = xx;
	}
}

int Inv(int a)
{
	ll x, y; gcd(a, x, M, y);
	x %= M;
	if (x < 0) x += M;
	return x;
}

int main()
{
	scanf("%d %d", &n, &M);
	if (M == 1) { printf("%I64d\n", ll(n) * (n - 1)); return 0; }
	pw[0] = inv[0] = 1;
	int coef = Inv(10);
	for (int i = 1; i <= n; i++) {
		pw[i] = ll(10) * pw[i - 1] % M;
		inv[i] = ll(coef) * inv[i - 1] % M;
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		neigh[a].push_back(ii(b, c));
		neigh[b].push_back(ii(a, c));
	}
	Traverse1(0);
	Traverse2(0);
	printf("%I64d\n", res);
	return 0;
}