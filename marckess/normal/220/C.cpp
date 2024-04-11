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
	int izq[400000], der[400000];

	ST () {
		fill(izq, izq+400000, 1e9);
		fill(der, der+400000, 1e9);
	}

	void lazyIzq (int i, int j, int pos) {
		int m = (i+j)/2;
		izq[pos*2] = min(izq[pos*2], izq[pos]);
		izq[pos*2+1] = min(izq[pos*2+1], izq[pos] + m - i + 1);
	}

	void updateIzq (int i, int j, int pos, int a, int b, int x, int k) {
		if (j < a || i > b)
			return;

		if (a <= i && j <= b) {
			if (i != j)
				lazyIzq(i, j, pos);
			izq[pos] = min(izq[pos], i-x+k);
			return;
		}

		int m = (i+j)/2;
		updateIzq(i, m, pos*2, a, b, x, k);
		updateIzq(m+1, j, pos*2+1, a, b, x, k);
	}

	void lazyDer (int i, int j, int pos) {
		int m = (i+j)/2;
		der[pos*2] = min(der[pos*2], der[pos] + j - m);
		der[pos*2+1] = min(der[pos*2+1], der[pos]);
	}

	void updateDer (int i, int j, int pos, int a, int b, int x, int k) {
		if (j < a || i > b)
			return;

		if (a <= i && j <= b) {
			if (i != j)
				lazyDer(i, j, pos);
			der[pos] = min(der[pos], x-j+k);
			return;
		}

		int m = (i+j)/2;
		updateDer(i, m, pos*2, a, b, x, k);
		updateDer(m+1, j, pos*2+1, a, b, x, k);
	}

	void obtRes (int i, int j, int pos) {
		if (i == j) {
			cout << min(der[pos], izq[pos]) << endl;
			return;
		}

		lazyDer(i, j, pos);
		lazyIzq(i, j, pos);

		int m = (i+j)/2;
		obtRes(i, m, pos*2);
		obtRes(m+1, j, pos*2+1);
	}
};

int n, a[100005], b[100005], x;
ST st;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = n-1; i >= 0; i--) {
    	cin >> x;
    	a[x] = i;
    }
    for (int i = n-1; i >= 0; i--) {
    	cin >> x;
    	b[x] = i;
    }

    for (int i = 1; i <= n; i++) {
    	if (a[i] < b[i]) {
    		int x = n - b[i];
    		int y = x + a[i] + 1;

    		st.updateIzq(1, n, 1, 1, x, 1, b[i] - a[i]);
    		st.updateDer(1, n, 1, x+1, y, y, 0);
    		st.updateIzq(1, n, 1, y+1, n, y+1, 1);
    	} else {
    		int x = a[i] - b[i] + 1;
    		int y = x + n - a[i] - 1;

    		st.updateDer(1, n, 1, 1, x, x, 0);
    		st.updateIzq(1, n, 1, x+1, y, x+1, 1);
    		st.updateDer(1, n, 1, y+1, n, n, a[i] - b[i] + 1);
    	}
    }

    st.obtRes(1, n, 1);

    return 0;
}