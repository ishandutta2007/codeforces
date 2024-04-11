#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int perm[Maxn];
int n;
bool was[Maxn];
bool mywas[Maxn];
bool ans;
int res[Maxn];

bool Prime(int x)
{
	if (x < 2) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;
	for (int i = 3; i * i <= x; i += 2)
		if (x % i == 0) return false;
	return true;
}

int Inv(int a, int n)
{
	int res = 1;
	int p = n - 2;
	while (p) {
		if (p & 1) res = ll(res) * a % n;
		p >>= 1; a = ll(a) * a % n;
	}
	return res;
}

void Solve(int n)
{
	if (n == 1) { ans = true; res[1] = 1; }
	else if (n == 4) { ans = true; res[1] = 1; res[2] = 3; res[3] = 2; res[4] = 4; }
	else if (Prime(n)) {
			ans = true;
			res[1] = 1; res[n] = n;
			for (int i = 2; i < n; i++)
				res[i] = ll(i) * Inv(i - 1, n) % n;
		} else ans = false;
	printf("%s\n", ans? "YES": "NO");
	if (ans)
		for (int i = 1; i <= n; i++)
			printf("%d\n", res[i]);
}

int main()
{
	scanf("%d", &n);
	Solve(n);
	return 0;
}