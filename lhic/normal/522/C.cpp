#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXN = 120000;

int n, k;
int a[MAXN];
int t[MAXN];
int r[MAXN];
int glfl[MAXN];
int ans[MAXN];

void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; ++i)
		scanf("%d", &a[i]);
	int fl = 0;
	int cnt = 0;
	for (int i = 0; i < n - 1; ++i)
		scanf("%d%d", &t[i], &r[i]);
	memset(glfl, 0, sizeof(glfl[0]) * k);
	memset(ans, 0, sizeof(ans[0]) * k);
	for (int i = 0; i < n - 1; ++i) {
		if (r[i] && !fl) {
			fl = 1;
			for (int j = i; j < n - 1; ++j)
				if (t[j] != 0)
					glfl[t[j] - 1] = 1;
			int go = 100001;
			for (int j = 0; j < k; ++j) {
				if (!glfl[j] && a[j] <= cnt) {
					ans[j] = 1;
					go = min(go, a[j]);
				}
			}
			cnt -= go;
		}
		if (t[i] != 0)
			--a[t[i] - 1];
		else
			++cnt;
	}
	for (int i = 0; i < k; ++i) {
		if (a[i] <= cnt)
			ans[i] = 1;
	}
	for (int i = 0; i < k; ++i)
		if (ans[i])
			printf("Y");
		else
			printf("N");
	printf("\n");
}


int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
		solve();
	return 0;
}