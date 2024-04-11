#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)
 
int n;
 
vector < pair <LL, int> > a;
vector <int> L, R;
 
int sgn(int i, int j, int k) {
	printf("2 %d %d %d\n", i, j, k);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}
LL area(int i, int j, int k) {
	printf("1 %d %d %d\n", i, j, k);
	fflush(stdout);
	LL x;
	scanf("%lld", &x);
	return x;
}
 
bool vis[1233];
 
int main() {
	read(n);
	int i = 1, j = 2;
	for (int k = 3; k <= n; k++) {
		if (sgn(i, j, k) == -1) j = k;
	}
	for (int k = 1; k <= n; k++) if (k != i && k != j) {
		a.push_back({area(i, j, k), k});
	}
	vis[i] = vis[j] = 1;
	L.push_back(i); L.push_back(j);
	int vised = 2;
	sort(a.begin(), a.end());
	for (auto v : a) {
		int k = v.second; vis[k] = 1;
		if (++vised == n) L.push_back(k);
		else for (int l = 1; l <= n; l++) if (!vis[l]) {
			int s = sgn(L.back(), k, l);
			if (s > 0) L.push_back(k);
			else R.push_back(k);
			break;
		}
	}
	printf("0");
	for (auto v : L) printf(" %d", v);
	reverse(R.begin(), R.end());
	for (auto v : R) printf(" %d", v);
	printf("\n");
}