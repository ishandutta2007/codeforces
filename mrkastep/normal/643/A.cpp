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

int n, a[5005], st[5005], ans[5005];

void solve() {
	int i, j, maxi = 0, k;
	for (i = 0; i < 5005; i++) {
		ans[i] = 0;
	}
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < 5005; j++) {
			st[j] = 0;
		}
		maxi = 0;
		k = 1e9;
		for (j = i; j < n; j++) {
			st[a[j]]++;
			if (maxi < st[a[j]]) {
				maxi = st[a[j]];
				k = a[j];
			}
			else {
				if (maxi == st[a[j]]) {
					k = min(k, a[j]);
				}
			}
			ans[k]++;
		}
	}
	for (i = 0; i < n; i++) {
		printf("%d ", ans[i+1]);
	}
	return;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	scanf("%d", &n);
	solve();
	return 0;
}