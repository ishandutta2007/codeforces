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

struct N {
	int c, i, res;

	bool operator < (const N ot) const {
		return c < ot.c;
	}
};

int n, k;
N v[300005];
ll res = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> v[i].c;
		v[i].i = i;
	}

	priority_queue<N> pq;
	for (int i = 0; i < n + k; i++) {
		if (i < n) {
			pq.push(v[i]);
		}

		if (i >= k) {
			N act = pq.top();
			pq.pop();

			res += ll(i - act.i) * act.c;
			v[act.i].res = i + 1;
		}
	}

	cout << res << endl;
	for (int i = 0; i < n; i++)
		cout << v[i].res << " ";
	cout << endl;

	return 0;
}