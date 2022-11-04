#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, k, p[MX], c[MX], q[MX];
ll acu = 0, res[MX];
priority_queue<int, vi, greater<int>> pq;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	for (int i = 0; i < n; i++)
		cin >> c[i];

	iota(q, q+n, 0);
	sort(q, q+n, [&] (int i, int j) {
		return p[i] < p[j];
	});

	for (int i = 0, j = 0; i < n; i++) {
		while (j < n && p[q[j]] < p[q[i]]) {
			acu += c[q[j]];
			pq.push(c[q[j]]);

			if (pq.size() > k) {
				acu -= pq.top();
				pq.pop();
			}

			j++;
		}

		res[q[i]] = c[q[i]] + acu;
	}

	for (int i = 0; i < n; i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}