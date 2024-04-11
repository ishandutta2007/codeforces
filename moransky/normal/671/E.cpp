// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e5 + 5;

int n, k, w[N], g[N], R[N], st[N], top;

LL s[N], h[N];

struct Node{
	LL s, mn;
};

Node operator + (Node x, Node y) {
	return (Node) { x.s + y.s, min(y.mn, y.s + x.mn) };
}

struct Seg{
	#define ls (p << 1)
	#define rs (p << 1 | 1)
	Node t[N << 2];
	void inline pushup(int p) {
		t[p] = t[ls] + t[rs];
	}
	void change(int p, int l, int r, int x, LL k) {
		if (l == r) {
			t[p].s += k;
			t[p].mn = min(0ll, t[p].s);
			return;
		}
		int mid = (l + r) >> 1;
		if (x <= mid) change(ls, l, mid, x, k);
		else change(rs, mid + 1, r, x, k);
		pushup(p);
	}
	Node query(int p, int l, int r, int x, int y) {
		if (x > y) return (Node) { 0, 0 };
		if (x <= l && r <= y) return t[p];
		int mid = (l + r) >> 1;
		if (y <= mid) return query(ls, l, mid, x, y);
		if (x > mid) return query(rs, mid + 1, r, x, y);
		return query(ls, l, mid, x, y) + query(rs, mid + 1, r, x, y);
	}
} t1, t2;

bool inline ask(int l, int r) {
	if (l == r) return 1;
	int t = R[l - 1];
	//cout << t << " mdmdmd\n";
	if (t >= r || !t) {
		t1.change(1, 1, n, r, k);
		Node u = t1.query(1, 1, n, l + 1, r);
		t1.change(1, 1, n, r, -k);
		return u.mn >= 0;
	} else {
		LL d = s[t] - s[l - 1];
		LL now = 0;
		now += -d + h[r - 1] - h[t];
		//cout << -d << "??" << h[r] << " " << h[t] << " " << now << endl;
		if (now > k) return 0;
		//cout << now << " aaaaaa\n";
		t1.change(1, 1, n, t, -d);
		t1.change(1, 1, n, r, k - now);
		Node u;
		//cout << t2.query(1, 1, n, t + 1, r).mn << " fidjijf\n";
		u = t1.query(1, 1, n, l + 1, t) + t2.query(1, 1, n, t + 1, r - 1) + t1.query(1, 1, n, r, r);
		t1.change(1, 1, n, r, -(k - now));
		t1.change(1, 1, n, t, d);
		return u.mn >= 0;
	}
}

bool inline chk(int x) {
	for (int r = x; r <= n; r++) {
		int l = r - x + 1;
		if (ask(l, r)) return 1;
	}
	return 0;
}

int main() {
	read(n), read(k);
	for (int i = 1; i < n; i++) read(w[i]);
	for (int i = 1; i <= n; i++) read(g[i]);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + g[i] - w[i];
	for (int i = n; i >= 0; i--) {
		while (top && s[i] <= s[st[top]]) top--;
		if (top) R[i] = st[top];
		st[++top] = i;
	}
	LL mn = s[1];
	for (int i = 1; i <= n; i++) {
		h[i] = h[i - 1];
		if (s[i] < mn) {
			t2.change(1, 1, n, i, mn - s[i]);
			h[i] += mn - s[i];
			mn = s[i];
		} 
	}
	for (int i = 2; i <= n; i++)
		t1.change(1, 1, n, i, g[i] - w[i - 1]), t2.change(1, 1, n, i, g[i] - w[i - 1]);
	
	
	
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		int R = min(r, mid + 10);
		int p = -1;
		for (int i = mid; i <= R; i++)
			if (chk(i)) p = i;
		if (p != -1) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", r);
	
//	
//	int ans = 1;
//	for (int i = 1; i <= n; i++) {
//		for (int j = i; j <= n; j++) {
//			if (ask(i, j) && j - i + 1 == 6) cout << i << " " << j << endl;
//		}
//	}
//	printf("%d\n", ans);
    return 0;
}