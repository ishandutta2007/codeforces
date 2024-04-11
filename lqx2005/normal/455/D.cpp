#include <bits/stdc++.h>
#define broken cerr << "running on " << __FUNCTION__ <<" "<< __LINE__ << endl
#define x first
#define y second
#define mp make_pair
#define sz(a) int((a).size())
#define par pair<int, int>
#define poly vector<int>
#define i64 long long
#define u64 unsigned long long
using namespace std;
const int B = 317, N = 1e5 + 10, T = N / B + 5;
int a[N];
struct Deque {
	int hd, n, delta;
	int a[B];
	Deque() {hd = n = delta = 0; }
	void init(vector<int> A, int delta) {
		this -> delta = delta;
		n = sz(A);
		for(int i = 0; i < n; i++) {
			a[i] = A[i];
		}
		hd = 0;
	}
	int & operator [](int x) {return a[(hd + x - delta) % n]; }
	
	void shift(int v) {
		hd = (hd - 1 + n) % n;
		a[hd] = v;
	}
	
	void shift(int l, int r, int v) {
		l -= delta, r -= delta;
		for(int i = r; i >= l; i--) {
			a[(hd + i + 1) % n] = a[(hd + i) % n];
		}
		a[(hd + l) % n] = v;
		return;
	}
}q[T];
int n, Q;
int cnt[T][N], bl[T], br[T], bid[N];

void init() {
	for(int i = 0; i * B + 1 <= n; i++) {
		bl[i] = i * B + 1, br[i] = min(n, (i + 1) * B);
		vector<int> arr(br[i] - bl[i] + 1);
		for(int j = bl[i]; j <= br[i]; j++) {
			bid[j] = i;
			arr[j - bl[i]] = a[j];
			cnt[i][a[j]]++;
		}
		q[i].init(arr, bl[i]);
	}
	return;
}

void change(int l, int r) {
	int L = bid[l], R = bid[r];
	if(L == R) {
		int b = q[L][r];
		q[L].shift(l, r - 1, b);
		return;
	}
	int pre = q[L][br[L]];
	cnt[L][pre]--;
	for(int i = L + 1; i < R; i++) {
		int v = q[i][br[i]];
		cnt[i][v]--, cnt[i][pre]++;
		q[i].shift(pre);
		pre = v;
	}
	int v = q[R][r];
	cnt[R][v]--, cnt[R][pre]++;
	q[R].shift(bl[R], r - 1, pre);
	pre = v;
	cnt[L][pre]++;
	q[L].shift(l, br[L] - 1, pre);
	return;
}

int query(int l, int r, int k) {
	int ans = 0;
	int L = bid[l], R = bid[r];
	if(bid[l] == bid[r]) {
		for(int i = l; i <= r; i++) {
			ans += q[L][i] == k;
		}
		return ans;
	}
	for(int i = L + 1; i < R; i++) ans += cnt[i][k];
	for(int i = l; i <= br[L]; i++) ans += q[L][i] == k;
	for(int i = bl[R]; i <= r; i++) ans += q[R][i] == k;
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	init();
	cin >> Q;
	int lastans = 0;
	for(int i = 1; i <= Q; i++) {
		int opt, l, r, k;
		cin >> opt >> l >> r;
		l = (l + lastans - 1) % n + 1;
		r = (r + lastans - 1) % n + 1;
		if(l > r) swap(l, r);
		if(opt == 1) {
			change(l, r);
		} else {
			cin >> k;
			k = (k + lastans - 1) % n + 1;
			cout << (lastans = query(l, r, k)) << endl;
		}
	}
    return 0;
}