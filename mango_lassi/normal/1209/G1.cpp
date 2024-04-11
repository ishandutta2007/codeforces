#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 2e5;
int group[N];
int siz[N];
int cou[N];

int app[N];
int lst[N];

int coll(int i) {
	if (group[i] != i) group[i] = coll(group[i]);
	return group[i];
}

bool join(int a, int b) {
	a = coll(a);
	b = coll(b);
	if (a == b) return false;
	siz[a] += siz[b];
	cou[a] = max(cou[a], cou[b]);
	app[a] = min(app[a], app[b]);
	group[b] = a;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// A ... B ... A: A and B must be changed to the same color
	//		First see what groups of colors must be changed to eachother.
	//		Then the cost is 

	int n, q;
	cin >> n >> q;

	for (int i = 0; i < N; ++i) {
		group[i] = i;
		siz[i] = 0;
		cou[i] = 0;
		app[i] = n;
	}

	vector<int> as(n);
	for (int i = 0; i < n; ++i) {
		cin >> as[i];
		--as[i];
		if (app[as[i]] != n) {
			lst[app[as[i]]] = i;
		} else {
			app[as[i]] = i;
		}
		++cou[as[i]];
		++siz[as[i]];
	}
	
	int mx = 0;
	for (int i = 0; i < n; ++i) {
		mx = max(mx, lst[i]);
		if (mx > i) join(as[i], as[i+1]);
	}

	int res = 0;
	for (int i = 0; i < n; ++i) {
		int j = coll(as[i]);
		if (i == app[j]) res += siz[j] - cou[j];
	}
	cout << res << '\n';
}