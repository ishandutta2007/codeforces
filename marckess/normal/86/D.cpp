#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S | (1 << j ) )
#define LSB(S) (S & (-S))

const int MN = 200005;
int n, m, a, b, cub[1000005], blo, v[MN], l[MN], r[MN];
ll res[MN], acu = 0;
ll q[MN];

bool comp (int a, int b) {
	int x = l[a] / blo;
	int y = l[b] / blo;
	if (x != y)
		return x < y;
	return r[a] < r[b];
}

void update (int i, int x) {
	acu += (2LL * cub[v[i]] * x + 1LL) * v[i];
	cub[v[i]] += x;
}

int main () {	
	scanf("%d%d", &n, &m);
	blo = sqrt(n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &v[i]);

	for (int i = 0; i < m; i++) {
		scanf("%d%d", &l[i], &r[i]);
		q[i] = i;
	}

	sort (q, q+m, comp);
	
	int a = 1, b = 0;
	for (int i = 0; i < m; i++) {
		int x = r[q[i]], y = l[q[i]];
		while (b < x)
			update(++b, 1);
		while (b > x)
			update(b--, -1);
		while (a < y)
			update(a++, -1);
		while (a > y)
			update(--a, 1);

		res[q[i]] = acu;
	}

	for (int i = 0; i < m; i++)
		printf("%I64d\n", res[i]);

	return 0;
}