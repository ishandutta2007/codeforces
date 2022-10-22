#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int m, n;
int a[Maxn];
int S;

int Inv(int a)
{
	int res = 1, p = m - 2;
	while (p) {
		if (p & 1) res = ll(res) * a % m;
		p >>= 1; a = ll(a) * a % m;
	}
	return res;
}

int main()
{
	scanf("%d %d", &m, &n);
	if (n == m) { printf("0 1\n"); return 0; }
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		S = (S + a[i]) % m;
	}
	if (n == 1) { printf("%d 0\n", a[0]); return 0; }
	int invn = Inv(n), invn1 = Inv(n - 1);
	int C = 2ll * ll(S) % m * invn % m * invn1 % m;
	int D = 2ll * invn1 % m;
	shuffle(a, a + n, rng);
	vector <ii> V;
	for (int i = 0; i < n; i++) {
		int d = (C - ll(a[i]) * D % m + m) % m;
		if (d) V.push_back(ii(Inv(d), a[i]));
	}
	shuffle(V.begin(), V.end(), rng);
	for (int i = 0; i < V.size(); i++) {
        bool ok = true;
        for (int j = 0; j < n; j++) {
            int tp = (a[j] - V[i].second + m) % m;
            ok = ll(tp) * V[i].first % m < n;
            swap(a[j], a[uniform_int_distribution<int>(0, j)(rng)]);
            if (!ok) break;
        }
        if (ok) { printf("%d %d\n", V[i].second, Inv(V[i].first)); return 0; }
	}
	printf("-1\n");
    return 0;
}