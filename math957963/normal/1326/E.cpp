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
#define N (1<<19)
#define MOD 1000000007
long long a[(2 * N)];
long long laz[(2 * N)];
int l[(2 * N)];
int r[(2 * N)];

//
void init(void) {
	f(i, N) {
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




long long ranchange(int ll, int rr, int k, long long x) {
	long long vl, vr;
	if (rr <= l[k] || r[k] <= ll)return 0;
	else if (ll <= l[k] && r[k] <= rr) {
		laz[k] += x;
		return (a[k]+laz[k]);
	}
	else {
		int mm = (l[k] + r[k]) / 2;
		if (l[k] < rr&&ll < mm) {
			vl = ranchange(ll, rr, 2 * k, x);
		}
		else vl = (a[2*k]+laz[2*k]);

		if (mm < rr&&ll < r[k]) {
			vr = ranchange(ll, rr, (2 * k) + 1, x);
		}
		else vr = (a[(2*k)+1]+laz[(2*k)+1]);

		a[k] = min(vl , vr);
		return (a[k]+laz[k]);
	}
}


//(0<=l<r<=n)(l<=x<r)(l,r,0)
long long sum_search(int ll, int rr, int k) {
	if (laz[k] != 0) {
		a[k] += laz[k];
		int mm = (l[k] + r[k]) / 2;
		if (k < N) {
			laz[(2 * k)] += laz[k];
			laz[(2 * k) + 1] += laz[k];
		}
		laz[k] = 0;
	}
	long long vl, vr;
	if (rr <= l[k] || r[k] <= ll)return MOD;
	else if (ll <= l[k] && r[k] <= rr) return a[k];
	else {
		vl = sum_search(ll, rr, 2 * k);
		vr = sum_search(ll, rr, (2 * k) + 1);
		a[k] = min(a[(2 * k)] , a[(2 * k) + 1]);
		return min(vl , vr);
	}
}


int main(void) {
	int n,q;
	int ans[N];
	vector<pair<int, int> >aa;
	int c[N];
	int b[N];
	int x, y;
	long long k;
	init();
	scanf("%d", &n);
	f(i, n) {
		scanf("%d", &x);
		aa.push_back(make_pair(-x, i + 1));
	}
	sort(aa.begin(), aa.end());
	f(i, n)c[i] = aa[i].second;
	f(i, n) {
		scanf("%d", &b[i]);
	}
	x = 0;
	y = 0;
	while (y < n) {
		k = sum_search(0, n, 1);
		if (k < 0) {
			ans[y] = n - x + 1;
			ranchange(0, b[y], 1, 1);
			y++;
		}
		else {
          if(x>=n)break;
			ranchange(0, c[x], 1, -1);
			x++;
		}

	}
	f(i, n) {
		printf("%d", ans[i]);
		if (i < (n - 1))printf(" ");
		else printf("\n");
	}
	return 0;
}