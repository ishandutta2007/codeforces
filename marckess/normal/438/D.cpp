#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

struct ST {
	int a[100005], ind[400005], mx[400005];
	ll sum[400005];

	void merge (int pos) {
		sum[pos] = sum[pos*2] + sum[pos*2+1];
		if (mx[pos*2] > mx[pos*2+1]) {
			mx[pos] = mx[pos*2];
			ind[pos] = ind[pos*2];
		} else {
			mx[pos] = mx[pos*2+1];
			ind[pos] = ind[pos*2+1];
		}
	}

	void build (int i, int j, int pos) {
		if (i == j) {
			sum[pos] = a[i];
			mx[pos] = a[i];
			ind[pos] = i;
			return;
		}

		int m = (i+j)/2;
		build(i, m, pos*2);
		build(m+1, j, pos*2+1);

		merge(pos);
	}

	void update (int i, int j, int pos, int k, int x) {
		if (k < i || k > j)
			return;

		if (i == j) {
			a[k] = x;
			sum[pos] = mx[pos] = x;
			return; 
		}

		int m = (i+j)/2;
		update(i, m, pos*2, k, x);
		update(m+1, j, pos*2+1, k, x);

		merge(pos);
	}

	ll obtSum (int i, int j, int pos, int a, int b) {
		if (i > b || j < a)
			return 0;

		if (a <= i && j <= b)
			return sum[pos];

		int m = (i+j)/2;
		return obtSum(i, m, pos*2, a, b) + obtSum(m+1, j, pos*2+1, a, b);
	}

	int obtMax (int i, int j, int pos, int a, int b) {
		if (i > b || j < a)
			return 0;

		if (a <= i && j <= b)
			return ind[pos];

		int m = (i+j)/2;
		int x = obtMax(i, m, pos*2, a, b);
		int y = obtMax(m+1, j, pos*2+1, a, b);

		if (this->a[x] > this->a[y])
			return x;
		return y;
	}
};

int n, m, op, l, r, x, k;
ST st;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    	cin >> st.a[i];

    st.build(1, n, 1);

    while (m--) {
    	cin >> op;

    	if (op == 1) {
    		cin >> l >> r;
    		cout << st.obtSum(1, n, 1, l, r) << endl;
    	} else if (op == 2) {
    		cin >> l >> r >> x;
    		while (st.a[(k = st.obtMax(1, n, 1, l, r))] >= x)
    			st.update(1, n, 1, k, st.a[k] % x);
    	} else {
    		cin >> k >> x;
    		st.update(1, n, 1, k, x);
    	}
    }

    return 0;
}