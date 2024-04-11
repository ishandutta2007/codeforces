#include <bits/stdc++.h>
using namespace std;
int n, L, R;
#define N 200111
int l[N], r[N];
void work() {
	scanf("%d%d%d", &n, &L, &R);
	for (int i = 1; i <= n; i++) l[i] = r[i] = 0;
	for (int i = 1; i <= L; i++) {
		int x;
		scanf("%d", &x);
		l[x]++;
	}
	for (int i = 1; i <= R; i++) {
		int x;
		scanf("%d", &x);
		r[x]++;
	}
	for (int i = 1; i <= n; i++) {
		int p = min(l[i], r[i]);
		l[i] -= p; r[i] -= p;
		L -= p; R -= p;
	}
	int c = 0;
	vector <int> ol, oR;
	for (int i = 1; i <= n; i++) if (l[i] % 2) ol.push_back(i);
	for (int i = 1; i <= n; i++) if (r[i] % 2) oR.push_back(i);
	while (ol.size() && oR.size()) {
		c++;
		l[ol.back()]--;
		r[oR.back()]--;
		ol.pop_back();
		oR.pop_back();
	}
	if (ol.size()) {
		for (int i = 1; i <= n; i++) {
			while (r[i] && ol.size()) {
				r[i]--;
				l[ol.back()]--;
				ol.pop_back();
				c++;
			}
		}
	}
	if (oR.size()) {
		for (int i = 1; i <= n; i++) {
			while (l[i] && oR.size()) {
				l[i]--;
				r[oR.back()]--;
				oR.pop_back();
				c++;
			}
		}
	}
	for (int i = 1; i <= n; i++) c += l[i] / 2 + r[i] / 2, l[i] %= 2, r[i] %= 2;
	for (int i = 1; i <= n; i++) c += l[i] + r[i];
	printf("%d\n", c);
}

int main() {
	int T;
	cin >> T;
	while (T--) work();
}