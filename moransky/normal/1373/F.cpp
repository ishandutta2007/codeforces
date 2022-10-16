#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1000005;

int n, a[N], b[N];

struct Pipe{
	int minIn, minOut, maxOut;
};

Pipe get(int x, int y) {
	if (x <= y) return (Pipe) { 0, y - x, y };
	else return (Pipe) { x - y, 0, y };
}

Pipe merge(Pipe x, Pipe y) {
	if (x.maxOut < y.minIn) return (Pipe) { -1, -1, -1 };
	if (x.minOut <= y.minIn) return (Pipe) { x.minIn + y.minIn - x.minOut, y.minOut, min(y.maxOut, y.minOut + x.maxOut - y.minIn) };
	else return (Pipe) { x.minIn, min(y.maxOut, y.minOut + x.minOut - y.minIn), min(y.maxOut, y.minOut + x.maxOut - y.minIn)  }; 
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		for (int i = 1; i <= n; i++) scanf("%d", b + i);
		Pipe cur = get(a[1], b[1]);
		bool ok = true;
		for (int i = 2; i <= n; i++) {
			cur = merge(cur, get(a[i], b[i]));
			if (cur.minIn == -1) { ok = false; break; }
		}
		if (cur.minOut < cur.minIn) ok = false;
		puts(ok ? "YES" : "NO");
	}
	return 0;
}