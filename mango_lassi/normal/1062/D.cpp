#include <iostream>
using namespace std;
typedef long long ll;

const int N = 1 + (int)1e5;
int gr[N];
ll gs[N];

int coll(int i) {
	if (gr[i] != i) gr[i] = coll(gr[i]);
	return gr[i];
}

void join(int a, int b, int x) {
	a = coll(a);
	b = coll(b);
	gs[a] += 4 * x;
	if (gr[a] != gr[b]) {
		gs[a] += gs[b];
		gr[b] = a;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		gr[i] = i;
		gs[i] = 0;
	}

	for (int i = 2; i <= n; ++i) {
		for (int x = 2; i*x <= n; ++x) {
			join(i, i*x, x);
		}
	}

	ll res = 0;
	for (int i = 2; i <= n; ++i) res = max(res, gs[i]);
	cout << res << '\n';
}