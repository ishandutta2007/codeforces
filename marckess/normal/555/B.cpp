#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, m;
ll l[MX], r[MX], a[MX], res[MX], q[MX];
vi pos[MX];

struct seg {
	int j, ind;
	seg () {}
	seg (int j, int ind) : j(j), ind(ind) {}
	bool operator < (const seg ot) const {
		return j > ot.j;
	}
};

priority_queue<seg> pq;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
	for (int i = 0; i < m; cin >> a[i++]);
	
	iota(q, q+m, 0);
	sort(q, q+m, [&] (int i, int j) {
		return a[i] < a[j];
	});
	sort(a, a+m);

	for (int i = 0; i < n-1; i++) {
		ll a = r[i+1] - l[i];
		ll b = l[i+1] - r[i];
		l[i] = b, r[i] = a;
	}

	n--;
	if (m < n) {
		cout << "No" << endl;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		l[i] = lower_bound(a, a+m, l[i]) - a;
		r[i] = upper_bound(a, a+m, r[i]) - a - 1;
		if (l[i] > r[i]) {
			cout << "No" << endl;
			return 0;
		}
	}

	for (int i = 0; i < n; i++)
		pos[l[i]].push_back(i);

	for (int i = 0; i < m; i++) {
		for (int x : pos[i]) pq.emplace(r[x], x);
		if (pq.size()) {
			if (pq.top().j < i) {
				cout << "No" << endl;
				return 0;
			}
			res[pq.top().ind] = q[i]+1;
			pq.pop();
		}
	}

	for (int i = 0; i < n; i++)
		if (!res[i]) {
			cout << "No" << endl;
			return 0;
		}

	cout << "Yes" << endl;
	for (int i = 0; i < n; i++) cout << res[i] << " ";
	cout << endl;

	return 0;
}