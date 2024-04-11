#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 1005;

int n, m, k;
int B[Maxn][Maxn];
int p;
int pw[Maxn];
int res;

bool getRes1(int &res)
{
	res = 1;
	bool found = false;
	bool ev = m % 2 == 0;
	for (int i = 1; i <= n; i++) {
		int fre = 0, cur = 1;
		for (int j = 1; j <= m; j++)
			if (B[i][j] != 0) cur *= B[i][j];
			else fre++;
		if (fre == 0) {
			if (cur == 1) { res = 0; return true; }
		} else if (fre == m && !found) found = true;
			   else res = ll(res) * ll(pw[fre - 1]) % ll(p);
		ev = !ev;
	}
	if (!found) return false;
	ev = !ev;
	if (ev) res = 0;
	return true;
}

bool getRes2(int &res)
{
	res = 1;
	bool found = false;
	bool ev = n % 2 == 0;
	for (int j = 1; j <= m; j++) {
		int fre = 0, cur = 1;
		for (int i = 1; i <= n; i++)
			if (B[i][j] != 0) cur *= B[i][j];
			else fre++;
		if (fre == 0) {
			if (cur == 1) { res = 0; return true; }
		} else if (fre == n && !found) found = true;
				else res = ll(res) * ll(pw[fre - 1]) % ll(p);
		ev = !ev;
	}
	if (!found) return false;
	ev = !ev;
	if (ev) res = 0;
	return true;
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		B[a][b] = c;
	}
	scanf("%d", &p);
	pw[0] = 1;
	for (int i = 1; i <= max(n, m); i++) pw[i] = pw[i - 1] * 2 % p;
	if (getRes1(res)) printf("%d\n", res);
	else { getRes2(res); printf("%d\n", res); }
	return 0;
}