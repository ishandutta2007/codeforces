#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 1005;

int n;
int X1[Maxn], Y1[Maxn], X2[Maxn], Y2[Maxn];
map <ii, set <int> > M;
ll res;

void Get(int ind, ll &A, ll &B, ll &C)
{
	A = Y2[ind] - Y1[ind];
	B = X1[ind] - X2[ind];
	C = ll(A) * X1[ind] + ll(B) * Y1[ind];
}

void Add(const ii &p, int ind)
{
	auto it = M.find(p);
	if (it == M.end()) {
		set <int> S; S.insert(ind);
		M.insert(make_pair(p, S));
	} else it->second.insert(ind);
}

void Intersect(int a, int b)
{
	ll A1, B1, C1; Get(a, A1, B1, C1);
	ll A2, B2, C2; Get(b, A2, B2, C2);
	ll det = A1 * B2 - A2 * B1;
	if (det == 0) return;
	else {
		ll sumx = B2 * C1 - B1 * C2;
		ll sumy = A1 * C2 - A2 * C1;
		if (sumx % det || sumy % det) return;
		ll x = sumx / det;
		ll y = sumy / det;
		if (min(X1[a], X2[a]) <= x && x <= max(X1[a], X2[a]) &&
			min(X1[b], X2[b]) <= x && x <= max(X1[b], X2[b]) &&
			min(Y1[a], Y2[a]) <= y && y <= max(Y1[a], Y2[a]) &&
			min(Y1[b], Y2[b]) <= y && y <= max(Y1[b], Y2[b])) {
			Add(ii(x, y), a);
			Add(ii(x, y), b);
		}
	}
}

ll gcd(ll a, ll b) { return a? gcd(b % a, a): b; }

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &X1[i], &Y1[i], &X2[i], &Y2[i]);
		int lenx = abs(X1[i] - X2[i]);
		int leny = abs(Y1[i] - Y2[i]);
		res += gcd(lenx, leny) + 1;
		for (int j = 0; j < i; j++)
			Intersect(j, i);
	}
	for (auto it: M)
		res -= (int(it.second.size()) - 1);
	cout << res << endl;
    return 0;
}