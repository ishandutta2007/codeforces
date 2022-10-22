#define  _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:526000000")

#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144 * 4LL
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()

unsigned long xor128() {
	static unsigned long x = 123456789, y = 362436069, z = 521288629, w = time(NULL);
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
void init() {
	iostream::sync_with_stdio(false);
	cout << fixed << setprecision(20);
}

#define int ll

template<typename T> class segtree {
private:
    int n, sz, h;
    vector<pair<T, int> > node;
    vector<T> lazy;
    void eval(int k) {
        if (lazy[k]) {
            node[k].first += lazy[k];
            if (k < n) {
                lazy[k * 2] += lazy[k], lazy[k * 2 + 1] += lazy[k];
            }
            lazy[k] = 0;
        }
    }

public:
    segtree(const vector<T>& v) : sz((int)v.size()), h(0) {
        n = 1;
        while (n < sz) n *= 2, h++;
        node.resize(2 * n, pair<T, int>(numeric_limits<T>::max(), sz));
        lazy.resize(2 * n, 0);
        for (int i = 0; i < sz; i++) {
            node[i + n] = make_pair(v[i], i);
        }
        for (int i = n - 1; i >= 1; i--) {
            node[i] = min(node[2 * i], node[2 * i + 1]);
        }
    }
    void range(int a, int b, T x, int k = 1, int l = 0, int r = -1) {
        if (r < 0) r = n;
        eval(k);
        if (b <= l || r <= a) {
            return;
        }
        if (a <= l && r <= b) {
            lazy[k] += x;
            eval(k);
        }
        else {
            range(a, b, x, 2 * k, l, (l + r) / 2);
            range(a, b, x, 2 * k + 1, (l + r) / 2, r);
            node[k] = min(node[2 * k], node[2 * k + 1]);
        }
    }
    pair<T, int> query(int a, int b) {
        a += n, b += n - 1;
        for (int i = h; i > 0; i--) eval(a >> i), eval(b >> i);
        b++;
        pair<T, int> res1 = make_pair(numeric_limits<T>::max(), sz);
        pair<T, int> res2 = make_pair(numeric_limits<T>::max(), sz);
        while (a < b) {
            if (a & 1) eval(a), res1 = min(res1, node[a++]);
            if (b & 1) eval(--b), res2 = min(res2, node[b]);
            a >>= 1, b >>= 1;
        }
        return min(res1, res2);
    }
    void print() {
        for (int i = 0; i < sz; i++) {
            pair<T, int> p;
            p = query(i, i + 1);
            cout << "st[" << i << "]: " << p.first << " " << p.second << endl;
        }
    }
};

int A[2000000];
int B[2000000];
vector<pair<int, int>> addon[2000000];

void solve(){
	int n, m, p;
	cin >> n >> m >> p;
    vector<ll> geko;
    for (int q = 0; q < seg_size; ++q) {
        geko.push_back(1e18);
    }

	REP(i, 2000000) {
		A[i] = 1e18;
		B[i] = 1e18;
	}
	REP(i, n) {
		int a, b;
		cin >> a >> b;
		A[a] = min(A[a], b);
	}
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		B[a] = min(B[a], b);
	}
	for (int i = 1e6; i >= 0; --i) {
		A[i] = min(A[i], A[i + 1]);
		B[i] = min(B[i], B[i + 1]);
	}

	REP(i, p) {
		int a, b, c;
		cin >> a >> b >> c;
		addon[a+1].push_back(mp(b + 1, c));
	}
    
    for (int q = 0; q <= 1e6; ++q) {
        geko[q] = B[q];
    }

    segtree<ll> sg(geko);

	int ans = -1e18;

	for (int i = 0; i <= 1e6; ++i) {
        for (auto x : addon[i]) {
            sg.range(x.first, seg_size, -x.second);
        }
        ans = max(ans, -sg.query(0, seg_size).first - A[i]);
	}
	cout << ans << endl;
}

#undef int

int main() {
	init();
	solve();
}