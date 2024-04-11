#pragma GCC optimize("O3")
#include <bits/stdc++.h>
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
#define INIT 0
#define INIT2 0
#define INIT3 0
long long a[(2 * N)];
long long laz[(2 * N)];
int l[(2 * N)];
int r[(2 * N)];

long long f1(long long x, long long y) {
	return (x + y);
}
long long f2(long long k, long long x, long long y) {
	return (((r[k] - l[k])*x) + y);
}
long long f3(long long x, long long y) {
	return (x + y);
}


void init(void) {
	f(i, (2 * N)) {
		a[i] = INIT2;
		laz[i] = INIT;
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



long long change(int ll, int rr, int k, long long x) {
	long long vl, vr;
	if ((rr <= l[k]) || (r[k] <= ll))return f2(k, laz[k], a[k]);
	if (laz[k] != INIT) {
		a[k] = f2(k, laz[k], a[k]);
		if (k < N) {
			laz[(2 * k)] = f1(laz[k], laz[(2 * k)]);
			laz[(2 * k) + 1] = f1(laz[k], laz[(2 * k) + 1]);
		}
		laz[k] = INIT;
	}
	if ((ll <= l[k]) && (r[k] <= rr)) {
		laz[k] = f1(x, laz[k]);
		return f2(k, laz[k], a[k]);
	}
	else {
		int mm = (l[k] + r[k]) / 2;
		if ((l[k] < rr) && (ll < mm)) {
			vl = change(ll, rr, 2 * k, x);
		}
		else vl = f2((2 * k), laz[(2 * k)], a[(2 * k)]);

		if ((mm < rr) && (ll < r[k])) {
			vr = change(ll, rr, (2 * k) + 1, x);
		}
		else vr = f2((2 * k) + 1, laz[(2 * k) + 1], a[(2 * k + 1)]);

		a[k] = f3(vl, vr);
		return f2(k, laz[k], a[k]);
	}
}

long long tsearch(int ll, int rr, int k) {
	if (laz[k] != INIT) {
		a[k] = (((r[k] - l[k])*laz[k]) + a[k]);
		if (k < N) {
			laz[(2 * k)] += laz[k];
			laz[(2 * k) + 1] += laz[k];
		}
		laz[k] = INIT;
	}
	long long vl, vr;
	if (rr <= l[k] || r[k] <= ll)return INIT3;
	else if (ll <= l[k] && r[k] <= rr) return (laz[k] + a[k]);
	else {
		if(ll<r[(2*k)])return tsearch(ll, rr, 2 * k);
		else return tsearch(ll, rr, (2 * k) + 1);
	}
}

long long search(int ll, int rr, int k) {
	if (laz[k] != INIT) {
		a[k] = f2(k, laz[k], a[k]);
		if (k < N) {
			laz[(2 * k)] = f1(laz[k], laz[(2 * k)]);
			laz[(2 * k) + 1] = f1(laz[k], laz[(2 * k) + 1]);
		}
		laz[k] = INIT;
	}
	long long vl, vr;
	if (rr <= l[k] || r[k] <= ll)return INIT3;
	else if (ll <= l[k] && r[k] <= rr) return f2(k, laz[k], a[k]);
	else {
		vl = search(ll, rr, 2 * k);
		vr = search(ll, rr, (2 * k) + 1);
		a[k] = f3(f2((2 * k), laz[(2 * k)], a[(2 * k)]), f2((2 * k) + 1, laz[(2 * k) + 1], a[(2 * k) + 1]));
		return f3(vl, vr);
	}
}


int main(void) {
	int n;
	char s[N];
	int ll, rr, mid, z;
	long long ans = 0;
	long long kk;
	f(i, N)s[i] = 0;
	scanf("%d", &n);
	cin >> s;
	int con = 0;
	init();
	f(i, n) {
		if (s[i] == '0') {
			con = i + 1;
			ans += search(0, i + 1, 1);
		}
		else {
			z = i - con;
			ll = -1;
			rr = i;
			while ((ll + 1) < rr) {
				mid = (ll + rr) / 2;
				kk = tsearch(mid, mid + 1, 1);
				if (kk <= z)rr = mid;
				else ll = mid;
			}
			change(rr, i + 1, 1, 1);
			ans += search(0, i + 1, 1);
		}
	}
	printf("%lld\n", ans);
	return 0;
}