#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
using namespace std;
#define f(i,n) for(int i=0;i<int(n);i++)
#define N (1<<20)
#define MOD 1000000007
int a[(2 * N)];
int laz[(2 * N)];

int l[(2 * N)];
int r[(2 * N)];


void init(void) {
	f(i, 2*N) {
		a[i] = 0;
		laz[i] = 0;
	}
	l[1] = 0;
	r[1] = N;
	for (int i = 1; i < N; i++) {
		l[(2 * i)] = l[i];
		r[(2 * i)] = (l[i] + r[i]) / 2;
		l[(2 * i) + 1] = (l[i] + r[i]) / 2;
		r[(2 * i) + 1] = r[i];
	}
	return;
}




int ranchange(int ll, int rr, int k, int x) {
	int vl, vr;
	if (rr <= l[k] || r[k] <= ll)return a[k];
	else if (ll <= l[k] && r[k] <= rr) {
		laz[k] += x;
		a[k] += x;
		return a[k];
	}
	else {
      		int mm = (l[k] + r[k]) / 2;
      	if (laz[k] != 0) {
		if (k < N) {
			laz[(2 * k)] += laz[k];	
			laz[(2 * k) + 1] += laz[k];
			a[(2 * k)] += laz[k];
			a[(2 * k) + 1] += laz[k];
		}
		laz[k] = 0;
	}
		if (l[k] < rr&&ll < mm) {
			vl = ranchange(ll, rr, 2 * k, x);
		}
		else vl = a[(2*k)];

		if (mm < rr&&ll < r[k]) {
			vr = ranchange(ll, rr, (2 * k) + 1, x);
		}
		else vr = a[(2*k)+1];
		a[k] = max(vl , vr);
		return a[k];
	}
}


int max_search(int ll, int rr, int k) {
	if (laz[k] != 0) {
		int mm = (l[k] + r[k]) / 2;
		if (k < N) {
			laz[(2 * k)] += laz[k];	
			laz[(2 * k) + 1] += laz[k];
			a[(2 * k)] += laz[k];
			a[(2 * k) + 1] += laz[k];
		}
		laz[k] = 0;
	}
	int vl, vr;
	if (rr <= l[k] || r[k] <= ll)return -MOD;
	else if (ll <= l[k] && r[k] <= rr) return a[k];
	else {
		vl = max_search(ll, rr, 2 * k);
		vr = max_search(ll, rr, (2 * k) + 1);
      a[k]=max(a[2*k],a[(2*k)+1]);
		return max(vl , vr);
	}
}


int main(void) {
	int n, m;
	vector<int>b;
	vector<int>c;
	int bb[300010];
	int cc[300010];
	int q;
	int d, x, y, z;
	int k;
	int al, ar, am;
	init();
	scanf("%d %d", &n, &m);
	f(i, n) {
		scanf("%d", &x);
		bb[i] = x;
		b.push_back(x);
	}
	b.push_back(-100);
	sort(b.begin(), b.end(),greater<int>());
	x = 0;
	for (int i = N - 1; i >= 0; i--) {
		while (b[x] >= i)x++;
		a[N+i] += x;
	}

	f(i, m) {
		scanf("%d", &x);
		cc[i] = x;
		c.push_back(x);
	}
	c.push_back(-100);
	sort(c.begin(), c.end(), greater<int>());
	x = 0;
	for (int i = N - 1; i >= 0; i--) {
		while (c[x] >= i)x++;
		a[N+i] -= x;
	}
	for (int i = N-1; i >= 1; i--)a[i] = max(a[(2 * i)], a[(2 * i) + 1]);

	scanf("%d", &q);
	f(qq, q) {
		scanf("%d", &d);
		if (d == 1) {
			scanf("%d %d", &x, &y);
			z = x;
			x = bb[x - 1];
			bb[z - 1] = y;
			if (x < y) {
				ranchange(x + 1, y + 1, 1, 1);
			}
			else if (x > y) {
				ranchange(y + 1, x + 1, 1, -1);
			}

		}
		else if (d == 2) {
			scanf("%d %d", &x, &y);
			z = x;
			x = cc[x - 1];
			cc[z - 1] = y;
			if (x < y) {
				ranchange(x + 1, y + 1, 1, -1);
			}
			else if (x > y) {
				ranchange(y + 1, x + 1, 1, 1);
			}
		}

		x = max_search(0, N, 1);
		if (x <= 0)printf("-1\n");
		else {
			al = 0;
			ar = N;
			while (al + 1 < ar) {
				am = (al + ar) / 2;
				x = max_search(am, N, 1);
				if (x > 0)al = am;
				else ar = am;
			}
			printf("%d\n", al);

		}

	}




	return 0;
}