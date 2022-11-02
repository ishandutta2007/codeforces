#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;

const int N = 100005;

int n, a[N], X[N << 1], Y[N << 1], tot, s1[N], t1, s2[N], b[N], t2;

bool inline solve() {
	int cnt = n + 1, x = 0;
	for (int i = n; i; i--) {
		if (a[i] == 0) continue;
		if (a[i] == 1) {
			s1[++t1] = i;
		} else if (a[i] == 2) {
			if (!t1) return false;
			s2[++t2] = i;
			b[i] = s1[t1--]; 
		} else if (a[i] == 3) {
			if (x) {
				--cnt;
				if (cnt == 0) return false;
				++tot;
				X[tot] = cnt, Y[tot] = i;
				++tot;
				X[tot] = cnt, Y[tot] = x;
				x = i;
			} else if (t2) {
				++tot; --cnt;
				if (cnt == 0) return false;
				X[tot] = cnt, Y[tot] = s2[t2];
				++tot;
				X[tot] = cnt, Y[tot] = b[s2[t2]];
				--cnt;
				if (cnt == 0) return false;
				++tot;
				X[tot] = cnt, Y[tot] = i;
				++tot;
				X[tot] = cnt, Y[tot] = s2[t2];
				t2--;
				x = i;
			} else if (t1) {
				++tot; --cnt;
				if (cnt == 0) return false;
				X[tot] = cnt, Y[tot] = s1[t1];
				--cnt;
				if (cnt == 0) return false;
				++tot;
				X[tot] = cnt, Y[tot] = i;
				++tot;
				X[tot] = cnt, Y[tot] = s1[t1];
				t1--;
				x = i;
			} else return false;
		}
	}
	while (t2) {
		++tot; --cnt;
		if (cnt == 0) return false;
		X[tot] = cnt, Y[tot] = s2[t2];
		++tot;
		X[tot] = cnt, Y[tot] = b[s2[t2]];
		t2--;
	}
	while (t1) {
		++tot; --cnt;
		if (cnt == 0) return false;
		X[tot] = cnt, Y[tot] = s1[t1];
		t1--;
	}
	return true;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	if (!solve()) puts("-1");
	else {
		printf("%d\n", tot);
		for (int i = 1; i <= tot; i++) printf("%d %d\n", X[i], Y[i]);
	}
	return 0;
}