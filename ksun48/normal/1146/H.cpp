#include<bits/stdc++.h>
using namespace std;

using ll = long long;

using pt = pair<ll, ll>;
#define X first
#define Y second

inline pt operator - (const pt& a, const pt& b) {
	return pt{a.X - b.X, a.Y - b.Y};
}
inline ll cross(pt a, pt b) {
	return a.X * b.Y - a.Y * b.X;
}
inline ll cross(pt a, pt b, pt c) {
	return cross(b-a, c-a);
}
inline bool dir(pt a, pt b, pt c) {
	ll v = cross(a,b,c);
	assert(v != 0);
	return v > 0;
}

const int MAXN = 310;
using bs = bitset<300>;
int N;
pt P[MAXN];
bs D[MAXN][MAXN];
ll numDir[MAXN][MAXN][2];
ll numCross[MAXN][MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> P[i].X >> P[i].Y;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			for (int k = 0; k < N; k++) {
				if (k == i || k == j) continue;
				bool d = dir(P[i], P[j], P[k]);
				D[i][j][k] = d;
				numDir[i][j][d] ++;
			}
		}
	}

	using ll = long long;
	ll res = ll(N) * ll(N-1) * ll(N-2) * ll(N-3) * ll(N-4) / 2 / 6;
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			for (int k = j+1; k < N; k++) {
				bs ij = D[i][j];
				bs jk = D[j][k];
				bs ki = D[k][i];

				if (!D[i][j][k]) {
					ij = D[j][i];
					jk = D[k][j];
					ki = D[i][k];
				}

				ij[i] = ij[j] = ij[k] = false;
				jk[i] = jk[j] = jk[k] = false;
				ki[i] = ki[j] = ki[k] = false;

				int c = (ij & jk & ki).count();
				numCross[i][k][j] = (ij&jk).count() - c;
				numCross[j][k][i] = (ij&ki).count() - c;
				numCross[i][j][k] = (jk&ki).count() - c;

				//cerr << i << ' ' << j << ' ' << k << ' ' << c << '\n';
				res -= ll(c) * ll(N - 3 - c);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (k == i || k == j) continue;
				//cerr << i << ' ' << j << ' ' << k << ' ' << int(numCross[i][j][k]) << '\n';
				res -= ll(numCross[i][j][k]) * ll(numCross[i][j][k] - 1) / 2;
			}
		}
	}

	ll res2 = 1ll * N * (N-1) * (N-2) * (N-3) * (N-4) / 120;

	ll res3 = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if (i == j) continue;
			ll a = numDir[i][j][0];
			res3 += a * (a-1) * (a-2) / 6;
		}
	}

	ll ans = res - 14 * res2 + 2 * res3;
	cout << ans << '\n';
	return 0;
}