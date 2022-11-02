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

ll n,a[200005],st[200005];
char c[200005];

void solve() {
	ll i, j,t,x;
	for (i = 0; i < 200005; i++) {
		st[i] = 0;
	}
	cin >> c;
	for (i = 0; i < n; i++) {
		scanf("%I64d", &a[i]);
	}
	t = 0;
	x = 0;
	for (i = 0; i < 200005&&t==0; i++) {
		if (st[x] == 1) {
			t = 1;
		}
		else {
			st[x] = 1;
			if (c[x] == '<') {
				x -= a[x];
			}
			else {
				x += a[x];
			}
		}
		if (x >= n||x<0) {
			printf("FINITE");
			return;
		}
	}
	printf("INFINITE");
	return;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	scanf("%I64d", &n);
	solve();
	return 0;
}