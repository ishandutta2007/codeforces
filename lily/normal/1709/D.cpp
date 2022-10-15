#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second


const int L = 19;
const int N = 2e5 + 5;
int n, m;
int w[L + 1][N];

int rmq(int l, int r) {
	if (l > r) swap(l, r);
	int o = __lg(r - l + 1);
	return max(w[o][l], w[o][r - (1 << o) + 1]);
}

int main() {
	read(n); read(m);
	for (int i = 1; i <= m; i++) read(w[0][i]);
	for (int j = 1; j <= L; j++)
		for (int i = 1, x = (1 << (j - 1)); i + x <= m; i++) {
			w[j][i] = max(w[j - 1][i], w[j - 1][i + x]);
		}
	int q;
	read(q);
	while (q--) {
		int xs, ys, xf, yf, k;
		read(xs); read(ys); read(xf); read(yf); read(k);
		if ((xs - xf) % k || (ys - yf) % k) puts ("NO");
		else {
			int mh = n - (n - xs) % k;
			if (rmq(ys, yf) >= mh) puts ("NO");
			else puts ("YES");
		}
	}


}