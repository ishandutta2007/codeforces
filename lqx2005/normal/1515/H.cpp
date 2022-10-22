#include<bits/stdc++.h>

using namespace std;

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()
#define x first
#define y second
#define mp make_pair
#define pb push_back

template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> par;
typedef long long LL;
typedef unsigned long long uLL;
typedef double db;
const int N = 2e5 + 10, LG = 20, T = (1 << (LG + 2)), U = (1 << LG) - 1;
int n, q;
int rt = 0;

int tag[T], zero[T], one[T], sz[T], ch[T][2], h[T], tot = 0;
int stk[T], top = 0;
int newd(int d) { 
	int u = top ? stk[top--] : ++tot;
	tag[u] = zero[u] = one[u] = sz[u] = ch[u][0] = ch[u][1] = 0;
	h[u] = d;
	return u; 
}

void del(int u) { stk[++top] = u; }

void upd(int p) { 
	if(h[p] != -1) {
		sz[p] = sz[ch[p][0]] + sz[ch[p][1]];
		zero[p] = zero[ch[p][0]] | zero[ch[p][1]];
		one[p] = one[ch[p][0]] | one[ch[p][1]];
	}
	return;
}

void rev(int p, int x) {
	if(!p) return;
	tag[p] ^= x;
	int a = zero[p], b = one[p];
	zero[p] = (a & (U ^ x)) | (b & x);
	one[p] = (b & (U ^ x)) | (a & x);
	return;
}

void pushd(int p) {
	if(h[p] == -1) return;
	if((tag[p] >> h[p] & 1)) swap(ch[p][0], ch[p][1]);
	rev(ch[p][0], tag[p]);
	rev(ch[p][1], tag[p]);
	tag[p] = 0;
	return;
}

void inser(int &p, int x, int dep = LG - 1) {
	if(!p) p = newd(dep);
	if(dep < 0) return sz[p] = 1, one[p] = x, zero[p] = U ^ x, void();
	pushd(p);
	inser(ch[p][(x >> dep & 1)], x, dep - 1);
	return upd(p), void();
}

void split(int p, int k, int x, int &a, int &b) {
	if(!p) return a = b = 0, void();
	if(x > k) return b = p, a = 0, void();
	if(x + (1 << (h[p] + 1)) - 1 <= k) return a = p, b = 0, void();
	pushd(p);
	a = p, b = newd(h[p]);
	split(ch[p][0], k, x, ch[a][0], ch[b][0]);
	split(ch[p][1], k, x | (1 << h[p]), ch[a][1], ch[b][1]);
	upd(a), upd(b);
	return;
}

int merge(int a, int b) {
	if(!a || !b) return a + b;
	pushd(a), pushd(b);
	ch[a][0] = merge(ch[a][0], ch[b][0]), ch[a][1] = merge(ch[a][1], ch[b][1]);
	del(b);
	return upd(a), a;
}

void Or(int p, int x) {
	if(!p) return;
	if(!(zero[p] & one[p] & x)) {
		rev(p, (x & zero[p]));
		return;
	}
	pushd(p);
	if(x >> h[p] & 1) ch[p][1] = merge(ch[p][0], ch[p][1]), ch[p][0] = 0;
	Or(ch[p][0], x), Or(ch[p][1], x);
	upd(p); 
	return;
}

int main() {
	ios::sync_with_stdio(false);
	h[0] = -1;
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for(int i = 1, a; i <= n; i++) {
		cin >> a;
		inser(rt, a);
	}
	for(int i = 1; i <= q; i++) {
		int t, l, r, x;
		cin >> t >> l >> r;
		int A, B, C; 
		split(rt, l - 1, 0, A, B);
		split(B, r, 0, B, C);
		if(t <= 3) {
			cin >> x;
			if(t == 1) {
				rev(B, U);
				Or(B, x ^ U);
				rev(B, U);
			} else if(t == 2) {
				Or(B, x);
			} else {
				rev(B, x);
			} 
		} else {
			cout << sz[B] << endl;
		}
		rt = merge(merge(A, B), C);
	}
	return 0;
}