#include <iostream>
using namespace std;

const int N = 2e5;
int ri[N];
int le[N];
int comp[N];
int nxt[N];
int pre[N];

int coll(int i) {
	if (comp[i] != i) comp[i] = coll(comp[i]);
	return comp[i];
}
void join(int a, int b) {
	a = coll(a);
	b = coll(b);
	
	// cerr << "link " << ri[a] << ' ' << le[b] << endl;
	pre[ri[a]] = le[b];
	nxt[le[b]] = ri[a];
	
	comp[b] = a;
	ri[a] = ri[b];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		le[i] = i;
		ri[i] = i;
		comp[i] = i;
		nxt[i] = -1;
		pre[i] = -1;
	}

	for (int i = 0; i < n-1; ++i) {
		int l, r;
		cin >> l >> r;
		--l; --r;
		join(l, r);
	}
	
	for (int j = 0; j < n; ++j) {
		// cerr << nxt[j] << ' ' << pre[j] << endl;
		if (pre[j] == -1) {
			while(j != -1) {
				cout << j+1 << ' ';
				j = nxt[j];
			}
			break;
		}
	}
	cout << '\n';
}