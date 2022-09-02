#include <iostream>
using namespace std;
typedef long long ll;

const int N = 1<<18;
ll max_v[2*N];
ll add_v[2*N];
int vals[N];

void push(int i) {
	if (add_v[i]) {
		max_v[i] += add_v[i];
		if (i < N) {
			add_v[2*i] += add_v[i];
			add_v[2*i+1] += add_v[i];
		}
		add_v[i] = 0;
	}
}

void addInt(int a, int b, int v, int ia = 0, int ib = N-1, int i = 1) {
	push(i);
	if (b < ia || ib < a) return;
	if (a <=ia && ib<= b) {
		add_v[i] += v;
		push(i);
	} else {
		int mid = (ia + ib) >> 1;
		addInt(a, b, v, ia, mid, 2*i);
		addInt(a, b, v, mid+1, ib, 2*i+1);
		max_v[i] = max(max_v[2*i], max_v[2*i+1]);
	}
}

int findZero(int ia = 0, int ib = N-1, int i = 1) {
	push(i);
	if (max_v[i] < 0) return -1;
	if (ia == ib) return (max_v[i] == 0 ? ia+1 : -1);
	
	int mid = (ia + ib) >> 1;
	int res = findZero(ia, mid, 2*i);
	if (res != -1) return res;
	return findZero(mid+1, ib, 2*i+1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		cin >> vals[i];
		addInt(i, i, vals[i]);
		addInt(i+1, N-1, -vals[i]);
	}
	for (int j = 0; j < q; ++j) {
		int x, v;
		cin >> x >> v;
		--x;
		int delta = v - vals[x];
		addInt(x, x, delta);
		addInt(x+1, N-1, -delta);
		vals[x] = v;

		if (vals[0] == 0) {
			cout << "1\n";
		} else {
			cout << findZero() << '\n';
		}
	}
}