#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

struct st {
	ll ca, cb;
	int a, b;
};
ll k;
int sa, sb;
int a[3][3];
int b[3][3];
st go[3][3];
st cur[3][3];
st tmp[3][3];

int wn(int x, int y) {
	int df = (x - y + 3) % 3;
	if (df == 1)
		return 1;
	return 0;
}

int main() {
	cin >> k >> sa >> sb;
	--sa, --sb;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			cin >> a[i][j], --a[i][j];
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			cin >> b[i][j], --b[i][j];
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j) {
			if (wn(i, j))
				++go[i][j].ca;
			if (wn(j, i))
				++go[i][j].cb;
			go[i][j].a = a[i][j];
			go[i][j].b = b[i][j];
		}
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			cur[i][j].a = i, cur[i][j].b = j;
	while (k) {
		while (!(k & 1)) {
			k >>= 1;
			for (int i = 0; i < 3; ++i)
				for (int j = 0; j < 3; ++j) {
					int x = go[i][j].a;
					int y = go[i][j].b;
					tmp[i][j].ca = go[i][j].ca + go[x][y].ca;
					tmp[i][j].cb = go[i][j].cb + go[x][y].cb;
					tmp[i][j].a = go[x][y].a;
					tmp[i][j].b = go[x][y].b;
				}
			for (int i = 0; i < 3; ++i)
				for (int j = 0; j < 3; ++j)
					go[i][j] = tmp[i][j];
		}
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j) {
				int x = cur[i][j].a;
				int y = cur[i][j].b;
				tmp[i][j].ca = cur[i][j].ca + go[x][y].ca;
				tmp[i][j].cb = cur[i][j].cb + go[x][y].cb;
				tmp[i][j].a = go[x][y].a;
				tmp[i][j].b = go[x][y].b;
			}
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				cur[i][j] = tmp[i][j];
		--k;
	}
	cout << cur[sa][sb].ca << " " << cur[sa][sb].cb << "\n";
	return 0;
}