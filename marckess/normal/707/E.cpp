#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

struct BIT {
	ll ft[2005][2005];
	int n, m;

	void init () {
		for (int i = 0; i < n; i++)
			fill(ft[i], ft[i]+1, 0);
	}

	void update (int i, int j, ll k) {
		for (int g = i; g < n; g += g & -g)
			for (int h = j; h < m; h += h & -h)
				ft[g][h] += k;
	}

	ll getSum (int i, int j) {
		ll sum = 0;

		for (int g = i; g; g -= g & -g)
			for (int h = j; h; h -= h & -h)
				sum += ft[g][h];

		return sum;
	}

	ll query (int x1, int y1, int x2, int y2) {
		return getSum(x2, y2)
			 - getSum(x2, y1-1)
			 - getSum(x1-1, y2)
			 + getSum(x1-1, y1-1);
	}
};

struct QUERY {
	int i, x1, x2, y1, y2;
};

int n, m, k, a, b, c, len[2005], q, qz = 0;
QUERY ask[1000005];
vvi sw, x, y, w;
ll res[1000005];
char s[10];
BIT ft;

#define updateFT(g,f) for (int i = 0; i < len[g]; i++) ft.update(x[g][i], y[g][i], f * w[g][i]);
void processGar (int g) {
	updateFT(g, 1);

	bool f = 1;
	int j = 0;
	for (int i = 0; i < qz; i++) {
		while (j < sw[g].size() && sw[g][j] < ask[i].i) {
			j++;
			f = !f;
		}

		if (f)
			res[i] += ft.query(
							ask[i].x1,
							ask[i].y1,
							ask[i].x2,
							ask[i].y2
					);
	}

	updateFT(g, -1);
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	scanf("%d %d %d", &n, &m, &k);

	sw = x = y = w = vvi(k+1);

	for (int i = 1; i <= k; i++) {
		scanf("%d", &len[i]);

		x[i] = y[i] = w[i] = vi(len[i]);

		for (int j = 0; j < len[i]; j++) {
			scanf("%d %d %d", &x[i][j], &y[i][j], &w[i][j]);
		}
	}

	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%s", s);

		if (s[0] == 'S') {
			scanf("%d", &a);
			sw[a].push_back(i);
		} else {
			scanf("%d %d %d %d", &ask[qz].x1,
								 &ask[qz].y1,
								 &ask[qz].x2,
				 				 &ask[qz].y2);
			ask[qz++].i = i;
		}
	}

	ft.n = n+3;
	ft.m = m+3;
	ft.init();
	
	for (int i = 1; i <= k; i++)
		processGar(i);

	for (int i = 0; i < qz; i++)
		printf("%lld\n", res[i]);

	return 0;
}