#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using t3 = tuple<int, int, int>;

int n, m;
int E[70][70], F[70][70];
int ans[300];
int C[10000][300], R[10000];

void solve() {
	memset(E, 0, sizeof E);
	memset(C, 0, sizeof C);
	memset(R, 0, sizeof R);
	scanf("%d%d", &n, &m);
	for(int i=1;i<=m;i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		z %= 3;
		E[x][y] = E[y][x] = 1;
		F[x][y] = F[y][x] = i;
		ans[i] = z;
	}
	int ce = 0;
	auto add_eq = [&](int a, int b, int c) {
		++ce;
		int rv = 0;
		for(int z : {a, b, c}) {
			if(ans[z] == -1) C[ce][z] = 1;
			else rv = (rv + 3 - ans[z]) % 3;
		}
		R[ce] = rv;
	};
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) {
		if(E[i][j] && E[i][k] && E[j][k]) {
			int x = F[i][j], y = F[i][k], z = F[j][k];
			add_eq(x, y, z);
		}
	}
	int p = 1, sv[300];
	memset(sv, -1, sizeof sv);
	for(int i=1;i<=m;i++) {
		int f = -1;
		for(int j=p;j<=ce;j++) {
			if(C[j][i]) {
				f = j;
				break;
			}
		}
		if(f == -1) continue;
		for(int j=i;j<=m;j++) swap(C[p][j], C[f][j]);
		swap(R[p], R[f]);
		for(int j=p+1;j<=m;j++) {
			if(C[j][i]) {
				int mul = C[j][i] * C[p][i];
				for(int k=i;k<=m;k++) {
					C[j][k] = (C[j][k] - mul * C[p][k]) % 3;
					if(C[j][k] < 0) C[j][k] += 3;
				}
				R[j] = (R[j] - mul * R[p]) % 3;
				if(R[j] < 0) R[j] += 3;
			}
		}
		sv[i] = p;
		++p;
	}

	for(int i=p;i<=ce;i++) {
		if(R[i]) {
			puts("-1");
			return;
		}
	}
	for(int i=m;i;i--) {
		if(sv[i] == -1) {
			if(ans[i] == -1) ans[i] = 0;
			continue;
		}
		int t = sv[i];
		ans[i] = R[t];
		for(int j=i+1;j<=m;j++) {
			ans[i] = (ans[i] - C[t][j] * ans[j]) % 3;
			if(ans[i] < 0) ans[i] += 3;
		}
		ans[i] = ans[i] * C[t][i] % 3;
	}
	for(int i=1;i<=m;i++) printf("%d ", ans[i] ? ans[i] : 3); puts("");
}

int main() {
	int TC; scanf("%d", &TC);
	for(int t=1;t<=TC;t++) {
		solve();
	}
	return 0;
}