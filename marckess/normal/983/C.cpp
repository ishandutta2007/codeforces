#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int dp[2005][720][10];
int hsh[10000], val[10000];

void precal () {
	int cn = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = i; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				for (int l = k; l < 10; l++) {
					hsh[l * 1000 + k * 100 + j * 10 + i] = cn++;
				}
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				for (int l = 0; l < 10; l++) {
					int x[] = {i, j, k, l};
					sort(x, x+4, greater<int>());
					val[l * 1000 + k * 100 + j * 10 + i] = hsh[x[0] * 1000 + x[1] * 100 + x[2] * 10 + x[3]];
				}
			}
		}
	}

	for (int i = 0; i < 2005; i++)
		for (int j = 0; j < 720; j++)
			for (int k = 0; k < 10; k++)
				dp[i][j][k] = -1;
}

int n, a[2005], b[2005];

int obtRes (int i, int w, int x, int y, int z, int f) {
	int h = val[w * 1000 + x * 100 + y * 10 + z];
	bool pos = 0;

	if (i == n && h == 0)
		return 0;

	int &res = dp[i][h][f];
	int acu = 0;
	if (res != -1)
		return res;
	res = 1e9;

	if (w == f) acu++, w = 0;
	if (!w) pos = 1;

	if (x == f) acu++, x = 0;
	if (!x) pos = 1;

	if (y == f) acu++, y = 0;
	if (!y) pos = 1;

	if (z == f) acu++, z = 0;
	if (!z) pos = 1;

	if (i == n && !w && !x && !y && !z)
		return res = acu;

	if (i < n && a[i] == f && pos) {
		acu++;
		if (!w) return res = acu + obtRes(i+1, b[i], x, y, z, f);
		if (!x) return res = acu + obtRes(i+1, w, b[i], y, z, f);
		if (!y) return res = acu + obtRes(i+1, w, x, b[i], z, f);
		return res = acu + obtRes(i+1, w, x, y, b[i], f);
	}

	int mn = 1e9;
	if (w) mn = min(mn, obtRes(i, w, x, y, z, w) + abs(f-w));
	if (x) mn = min(mn, obtRes(i, w, x, y, z, x) + abs(f-x));
	if (y) mn = min(mn, obtRes(i, w, x, y, z, y) + abs(f-y));
	if (z) mn = min(mn, obtRes(i, w, x, y, z, z) + abs(f-z));
	if (i < n && pos) mn = min(mn, obtRes(i, w, x, y, z, a[i]) + abs(f-a[i]));

	return res = acu + mn;
}

int main () {
    //ios_base::sync_with_stdio(0); cin.tie(0);
	precal();

	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &a[i], &b[i]);

	printf("%d\n", obtRes(0, 0, 0, 0, 0, 1));

    return 0;
}