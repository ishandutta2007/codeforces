#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

struct nodo {
	nodo *sig[2];
	int val;

	nodo () {
		sig[0] = sig[1] = 0;
		val = 0;
	}
};

nodo *vn[1005][1005];
int n, m, q, a, b, c, d, h, w;

void constr () {
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			vn[i][j] = new nodo();

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++) {
			vn[i][j]->sig[0] = vn[i][j+1];
			vn[i][j]->sig[1] = vn[i+1][j];
		}
}

void swap (nodo *a, nodo *b, int d, int n) {
	while (n--) {
		swap(a->sig[1-d], b->sig[1-d]);
		a = a->sig[d];
		b = b->sig[d];
	}
}

nodo* obtDir (int i, int j) {
	nodo *dir = vn[0][0];

	while (j--)
		dir = dir->sig[0];

	while (i--)
		dir = dir->sig[1];

	return dir;
}

void swap () {
	nodo *a1 = obtDir(a-1, b);
	nodo *a2 = obtDir(c-1, d);

	nodo *b1 = obtDir(a, b-1);
	nodo *b2 = obtDir(c, d-1);

	nodo *c1 = obtDir(a+h-1, b);
	nodo *c2 = obtDir(c+h-1, d);

	nodo *d1 = obtDir(a, b+w-1);
	nodo *d2 = obtDir(c, d+w-1);

	swap(a1, a2, 0, w);
	swap(b1, b2, 1, h);
	swap(c1, c2, 0, w);
	swap(d1, d2, 1, h);
}

void imprRes () {
	for (int i = 1; i <= n; i++) {
		nodo *p = vn[i][0]->sig[0];

		for (int j = 1; j <= m; j++) {
			cout << p->val << " ";
			p = p->sig[0];
		}

		cout << endl;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> q;
	constr();

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> vn[i][j]->val;

	while (q--) {
		cin >> a >> b >> c >> d >> h >> w;
		swap();
	}

	imprRes();

	return 0;
}