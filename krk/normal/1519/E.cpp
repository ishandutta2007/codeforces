#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> llll;
typedef pair <int, int> ii;

const int Maxn = 400005;

int n;
int a[Maxn], b[Maxn], c[Maxn], d[Maxn];
llll A[Maxn], B[Maxn];
vector <llll> un;
vector <ii> neigh[Maxn];
int cur, tim[Maxn];
vector <ii> res;

ll gcd(ll a, ll b) { return a? gcd(b % a, a): b; }

llll Get(ll x1, ll x2, ll y1, ll y2)
{
	ll a = x1 * y2;
	ll b = x2 * y1;
	ll g = gcd(a, b);
	return llll(a / g, b / g);
}

void Add(int &old, int nw)
{
	if (nw == 0) return;
	if (old == 0) old = nw;
	else {
		res.push_back(ii(old, nw));
		old = 0;
	}
}

int Visit(int v)
{
	int my = 0;
	tim[v] = ++cur;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i].first;
		if (!tim[u]) {
			int g = Visit(u);
			if (g) Add(g, neigh[v][i].second);
			else Add(my, neigh[v][i].second);
		} else if (tim[v] < tim[u])
			Add(my, neigh[v][i].second);
	}
	return my;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
		A[i] = Get(a[i] + b[i], b[i], c[i], d[i]);
		B[i] = Get(a[i], b[i], c[i] + d[i], d[i]);
		un.push_back(A[i]);
		un.push_back(B[i]);
	}
	sort(un.begin(), un.end());
	un.erase(unique(un.begin(), un.end()), un.end());
	for (int i = 0; i < n; i++) {
		int a = lower_bound(un.begin(), un.end(), A[i]) - un.begin();
		int b = lower_bound(un.begin(), un.end(), B[i]) - un.begin();
		neigh[a].push_back(ii(b, i + 1));
		neigh[b].push_back(ii(a, i + 1));
	}
	for (int i = 0; i < un.size(); i++) if (!tim[i])
		Visit(i);
	printf("%d\n", int(res.size()));
	for (int i = 0; i < res.size(); i++)
		printf("%d %d\n", res[i].first, res[i].second);
    return 0;
}