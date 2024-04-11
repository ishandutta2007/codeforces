#include <bits/stdc++.h>
#define broken cerr << "running on " << __FUNCTION__ <<" "<< __LINE__ << endl
#define x first
#define y second
#define sz(a) int((a).size())
#define ll long long
#define ull unsigned long long
#define mid ((l + r) >> 1)
#define ls (p + 1)
#define rs (p + ((mid - l + 1) << 1))
using namespace std;
const int N = 1e5 + 10;
struct Mat {
	int a[3][3];
	Mat() {memset(a, 0x3f, sizeof(a));}
	friend Mat operator * (const Mat a, const Mat b) {
		Mat c;
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				for(int k = 0; k < 3; k++) {
					c.a[i][j] = min(a.a[i][k] + b.a[k][j], c.a[i][j]);
				}
			}
		}
		return c;
	}
};
int n, q;
char s[N];
Mat t[N << 1];

void updata(int p, int c) {
	memset(t[p].a, 0x3f, sizeof(t[p].a));
	if(c == 0) {
		t[p].a[0][1] = 0;
		t[p].a[0][0] = 1;
		t[p].a[1][1] = 0;
		t[p].a[2][2] = 0;
	}
	if(c == 1) {
		t[p].a[0][0] = 0;
		t[p].a[1][1] = 1;
		t[p].a[1][2] = 0;
		t[p].a[2][2] = 0;
	}
	if(c == 2) {
		t[p].a[0][0] = 0;
		t[p].a[1][1] = 0;
		t[p].a[2][2] = 1;
	}
	return;
}

void modify(int p, int l, int r, int x, int c) {
	if(l == r) return updata(p, c);
	if(x <= mid) modify(ls, l, mid, x, c);
	else modify(rs, mid + 1, r, x, c);
	t[p] = t[ls] * t[rs];
	return;
}

void solve() {
	cin >> n >> q;
	cin >> (s + 1);
	for(int i = 1; i <= n; i++) modify(1, 1, n, i, s[i] - 'a');
	for(int i = 1; i <= q; i++) {
		char x;
		int p;
		cin >> p >> x;
		modify(1, 1, n, p, x - 'a');
		int ans = INT_MAX;
		for(int j = 0; j < 3; j++) for(int k = 0; k < 3; k++) ans = min(ans, t[1].a[j][k]);
		cout << ans << endl;
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	solve();
	// for(cin >> t; t--; solve());
	return 0;
}