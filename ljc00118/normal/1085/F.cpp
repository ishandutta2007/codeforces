#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie();
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 2e5 + 5;

struct SookeTree {
	int sum[N << 2];
	
	SookeTree () { memset(sum, 0, sizeof(sum)); }
	
	void change(int u, int l, int r, int x, int y) {
		sum[u] += y; if(l == r) return;
		int mid = (l + r) >> 1;
		if(mid >= x) change(u << 1, l, mid, x, y);
		else change(u << 1 | 1, mid + 1, r, x, y);
	}
	
	int query(int u, int L, int R, int l, int r) {
//		fprintf(stderr, "L = %d, R = %d, l = %d, r = %d\n", L, R, l, r);
		if(l > r) return 0;
		if(l <= L && R <= r) return sum[u];
		int mid = (L + R) >> 1, ans = 0;
		if(mid >= l) ans += query(u << 1, L, mid, l, r);
		if(mid + 1 <= r) ans += query(u << 1 | 1, mid + 1, R, l, r);
		return ans;
	}
}t[3];

char c[N]; int a[N];
int n, m;

int calc(char c) {
	if(c == 'P') return 0;
	if(c == 'R') return 1;
	return 2;
}

int solve() {
	int ans = 0; int L[3] = {-1, -1, -1}, R[3] = {-1, -1, -1};
	int l = 1, r = n, res = -1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(t[0].query(1, 1, n, 1, mid)) res = mid, r = mid - 1;
		else l = mid + 1;
	}
	L[0] = res;
	l = 1, r = n, res = -1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(t[0].query(1, 1, n, mid, n)) res = mid, l = mid + 1;
		else r = mid - 1;
	}
	R[0] = res;
	l = 1, r = n, res = -1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(t[1].query(1, 1, n, 1, mid)) res = mid, r = mid - 1;
		else l = mid + 1;
	}
	L[1] = res;
	l = 1, r = n, res = -1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(t[1].query(1, 1, n, mid, n)) res = mid, l = mid + 1;
		else r = mid - 1;
	}
	R[1] = res;
	l = 1, r = n, res = -1;
	l = 1, r = n, res = -1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(t[2].query(1, 1, n, 1, mid)) res = mid, r = mid - 1;
		else l = mid + 1;
	}
	L[2] = res;
	l = 1, r = n, res = -1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(t[2].query(1, 1, n, mid, n)) res = mid, l = mid + 1;
		else r = mid - 1;
	}
	R[2] = res;
	l = 1, r = n, res = -1;
	for(register int i = 0; i <= 2; i++) if(t[i].query(1, 1, n, 1, n) == n) return n;
	if(L[1] == -1) ans += t[2].query(1, 1, n, 1, n);
	else if(~L[0]) ans += t[2].query(1, 1, n, L[0], R[0]);
	if(L[2] == -1) ans += t[0].query(1, 1, n, 1, n);
	else if(~L[1]) ans += t[0].query(1, 1, n, L[1], R[1]);
	if(L[0] == -1) ans += t[1].query(1, 1, n, 1, n);
	else if(~L[2]) ans += t[1].query(1, 1, n, L[2], R[2]);
	if(~L[0] && ~L[1]) ans += t[2].query(1, 1, n, 2, min(L[0], L[1]));
	if(~L[0] && ~L[2]) ans += t[1].query(1, 1, n, 2, min(L[2], L[0]));
	if(~L[1] && ~L[2]) ans += t[0].query(1, 1, n, 2, min(L[1], L[2]));
	if(~R[0] && ~R[1]) ans += t[2].query(1, 1, n, max(R[1], R[0]), n - 1);
	if(~R[0] && ~R[2]) ans += t[1].query(1, 1, n, max(R[0], R[2]), n - 1);
	if(~R[1] && ~R[2]) ans += t[0].query(1, 1, n, max(R[2], R[1]), n - 1);
	if(a[1] == 0 && ~L[1] && ~L[2]) ans++;
	if(a[1] == 1 && ~L[0] && ~L[2]) ans++;
	if(a[1] == 2 && ~L[1] && ~L[0]) ans++;
	if(a[n] == 0 && ~L[1] && ~L[2]) ans++;
	if(a[n] == 1 && ~L[0] && ~L[2]) ans++;
	if(a[n] == 2 && ~L[1] && ~L[0]) ans++;
	return ans;
}

int main() {
	read(n); read(m); scanf("%s", c + 1);
	for(register int i = 1; i <= n; i++) {
		a[i] = calc(c[i]);
		t[a[i]].change(1, 1, n, i, 1);
	}
	print(solve(), '\n');
	for(register int i = 1; i <= m; i++) {
		int tt; char c;
		read(tt); c = getchar();
		while(c < 'A' || c > 'Z') c = getchar();
		int now = calc(c);
		t[a[tt]].change(1, 1, n, tt, -1);
		a[tt] = now;
		t[a[tt]].change(1, 1, n, tt, 1);
		print(solve(), '\n');
	}
	return 0;
}