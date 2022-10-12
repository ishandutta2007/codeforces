#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
#define ran 2000010
int n, a[ran], b[ran];
int c[ran], lc;

int ace[ran], v[ran], e[ran];
int ancestor(int x) { return x - ace[x] ? ace[x] = ancestor(ace[x]) : x; }
bool chk(int x) {
	for (int i = 0; i < lc; i++) {
		ace[i] = i;
		v[i] = 1;
		e[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		int A = a[i], B = b[i];
		if (A > x)return false;
		if (B > x) {
			A = ancestor(A);
			e[A] ++;
			if (e[A] > v[A])return false;
		}
		else {
			A = ancestor(A);
			B = ancestor(B);
			if (A == B) {
				e[A] ++;
				if (e[A] > v[A])return false;
			}
			else {
				e[A] += e[B];
				v[A] += v[B];
				ace[B] = A;
				e[A] ++;
				if (e[A] > v[A])return false;
			}
		}
	}
	return true;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a[i], &b[i]);
		c[lc++] = a[i];
		c[lc++] = b[i];
	}
	sort(c, c + lc);
	lc = unique(c, c + lc) - c;
	for (int i = 1; i <= n; i++) {
		a[i] = lower_bound(c, c + lc, a[i]) - c;
		b[i] = lower_bound(c, c + lc, b[i]) - c;
	}
	int lo = 0, hi = lc;
	while (lo != hi) {
		int mi = (lo + hi) / 2;
		if (chk(mi)) hi = mi;
		else
			lo = mi + 1;
	}
	printf("%d\n", lo == lc ? -1 : c[lo]);
	return 0;
}