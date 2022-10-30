#include<stdio.h>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<math.h>
#include<queue>
#include<iostream>
#include<cstring>
#include<time.h>
#include<stack>
#include<complex>
#include<set>

#pragma warning (disable: 4996)

#define mp make_pair
#define ll long long int

using namespace std;

ll n, m, t, d[1000005];

void solve() {
	ll i, j, x, a = 0, b = 1, sum = 0;
	for (i = 0; i < m; i++) {
		scanf("%I64d", &t);
		if (t == 2) {
			if (a % 2 == 0) {
				a++;
				a %= n;
			}
			else {
				a--;
				a += n;
				a %= n;
			}
			if (b % 2 == 0) {
				b++;
				b %= n;
			}
			else {
				b--;
				b += n;
				b %= n;
			}
		}
		else {
			scanf("%I64d", &x);
			x %= n;
			a += x;
			b += x;
			a += n;
			b += n;
			a %= n;
			b %= n;
		}
	}
	x = 1;
	sum = 0;
	for (i = a; sum < n / 2; i += 2) {
		i %= n;
		d[i] = x;
		x += 2;
		sum++;
	}
	x = 2;
	sum = 0;
	for (i = b; sum < n / 2; i += 2) {
		i %= n;
		d[i] = x;
		x += 2;
		sum++;
	}
	for (i = 0; i < n; i++) {
		printf("%I64d ", d[i]);
	}
	return;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	scanf("%I64d%I64d", &n, &m);
	solve();
	return 0;
}