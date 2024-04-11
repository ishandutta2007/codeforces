#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int MAX_N = 200000 + 10, inf = ~0U >> 2;

inline void UpdateMax(int&x, int c) {
	x = max(x, c);
}
inline void UpdateMin(int&x, int c) {
	x = min(x, c);
}

//1..n
struct SegTree {
	int Max[MAX_N * 4], Min[MAX_N * 4], st, n;
	void set(int x) {
		Max[x] = max(Max[x * 2], Max[x * 2 + 1]);
		Min[x] = min(Min[x * 2], Min[x * 2 + 1]);
	}
	void Build(int l, int r, int Data[]) {
		memset(Max, 0, sizeof Max);
		for (int i = 0; i < MAX_N * 4; ++i) {
			Min[i] = inf;
		}

		st = l - 1;
		int s = r - l;
		n = 1;
		while (n <= s + 10)
			n <<= 1;
		for (int i = l; i < r; i++)
			Max[i - st + n] = Data[i], Min[i - st + n] = Data[i];
		for (int i = n - 1; i >= 1; i--)
			set(i);
	}
	void Change(int p, int s) {
		p -= st;
		p += n;
		Max[p] = s, Min[p] = s;
		for (p >>= 1; p; p >>= 1)
			set(p);
	}
	int QueryMax(register int s, register int t) {
		s -= st;
		t -= st;
		s--;
		t++;
		register int ret = -inf;
		for (s += n, t += n; s ^ t ^ 1; s >>= 1, t >>= 1) {
			if (~s & 1)
				UpdateMax(ret, Max[s ^ 1]);
			if (t & 1)
				UpdateMax(ret, Max[t ^ 1]);
		}
		return ret;
	}
	int QueryMin(register int s, register int t) {
		s -= st;
		t -= st;
		s--;
		t++;
		register int ret = inf;
		for (s += n, t += n; s ^ t ^ 1; s >>= 1, t >>= 1) {
			if (~s & 1)
				UpdateMin(ret, Min[s ^ 1]);
			if (t & 1)
				UpdateMin(ret, Min[t ^ 1]);
		}
		return ret;
	}
} ST;

int n, Q;
int fa[MAX_N];
vector<int> my[MAX_N];

int fd(int x) {
	return x == fa[x] ? x : fa[x] = fd(fa[x]);
}

void unite(int a, int b) {
	a = fd(a);
	b = fd(b);
	if (a == b)
		return;
	if (my[b].size() > my[a].size()) //merge b into a
		swap(a, b);

	for (vector<int>::iterator e = my[b].begin(); e != my[b].end(); ++e) {
		ST.Change(*e, a);
		my[a].push_back(*e);
	}
	my[b].clear();
	fa[b] = a;
}

int main() {
	cin >> n >> Q;
	for (int i = 1; i <= n; ++i) {
		fa[i] = i;
		my[i].push_back(i);
	}
	ST.Build(1, n + 1, fa);

	for (int i = 0; i < Q; ++i) {
		int type, x, y;
		scanf("%d%d%d", &type, &x, &y);
		if (type == 1) {
			x = fd(x), y = fd(y);
			if (x == y)
				continue;
			else
				unite(x, y);
		} else if (type == 2) {
			//x..y
			for (;;) {
				int a = ST.QueryMin(x, y);
				int b = ST.QueryMax(x, y);
				if (a == b)
					break;
				unite(a, b);
			}
		} else {
			if (fd(x) == fd(y)) {
				puts("YES");
			} else {
				puts("NO");
			}
		}
	}
}