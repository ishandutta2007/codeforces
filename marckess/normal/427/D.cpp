#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

void obtLCP (string &a, string &b, vvi &lcp) {
	for (int i = a.size() - 1; i >= 0; i--) {
		for (int j = b.size() - 1; j >= 0; j--) {
			if (a[i] == b[j]) {
				lcp[i][j] = 1;
				if (i < a.size() - 1 && j < b.size() - 1)
					lcp[i][j] += lcp[i+1][j+1];
			}
		}
	}
}

void obtMXCP (vvi &lcp, vi &mx) {
	for (int i = 0; i < lcp.size(); i++) {
		for (int j = 0; j < lcp[i].size(); j++)
			if (i != j)
				mx[i] = max(mx[i], lcp[i][j]);
		if (i + mx[i] < lcp.size())
			mx[i]++;
		else
			mx[i] = 1e9;
	}
}

string a, b;
vvi ab, aa, bb;
vi amx, bmx;

int obtRes () {
	unsigned int res = -1;

	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b.size(); j++)
				if (max(amx[i], bmx[j]) <= ab[i][j])
					res = min(res, (unsigned int)max(amx[i], bmx[j]));

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> a >> b;	

	ab = vvi(a.size(), vi(b.size()));
	aa = vvi(a.size(), vi(a.size()));
	bb = vvi(b.size(), vi(b.size()));

	obtLCP(a, b, ab);
	obtLCP(a, a, aa);
	obtLCP(b, b, bb);

	amx = vi(a.size());
	bmx = vi(b.size());

	obtMXCP(aa, amx);
	obtMXCP(bb, bmx);

	cout << obtRes() << endl;

	return 0;
}