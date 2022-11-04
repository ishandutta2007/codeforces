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

struct PST {
	PST *izq, *der;
	int cn;

	PST () : izq(der = 0), cn(0) {}
	PST (PST *izq, PST *der) : izq(izq), der(der) {
		cn = izq->cn + der->cn;
	}
	PST (int x) : izq(der = 0), cn(x) {}

	void build (int i, int j) {
		if (i == j)
			return;

		int m = (i+j)/2;
		izq = new PST();
		der = new PST();
		izq->build(i, m);
		der->build(m+1, j);
	}

	PST *update (int i, int j, int x) {
		if (x < i || j < x)
			return this;

		if (i == j)
			return new PST(cn + 1);

		int m = (i+j)/2;
		return new PST(izq->update(i, m, x), der->update(m+1, j, x));
	}

	int query (int i, int j, int x) {
		if (j < x)
			return 0;

		if (x <= i)
			return cn;

		int m = (i+j)/2;
		return izq->query(i, m, x) + der->query(m+1, j, x);
	}
};

const int MX = 200005;
int n, a[MX];
PST *st[MX];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    	a[i] = min(a[i], n);
    }

    st[0] = new PST();
    st[0]->build(1, MX);
    for (int i = 1; i <= n; i++)
    	st[i] = st[i-1]->update(1, MX, a[i]);

    ll res = 0;
    for (int i = 1; i <= n; i++)
    	if (a[i] > i)
    		res += st[a[i]]->query(1, MX, i) - st[i]->query(1, MX, i);

    cout << res << endl;

    return 0;
}