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

const int MX = 200005;
int n, a[MX], b[MX], Q, k, l;
vi pos[MX], q;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		pos[a[i]].push_back(i);
	}

	for (int i = 1; i <= n; i++)
		if (pos[i].size())
			q.push_back(pos[i].back());

	sort(ALL(q), [&] (int i, int j) {
		return b[i] > b[j];
	});

	cin >> Q;
	while (Q--) {
		set<int> c;
		cin >> k;

		while (k--) {
			cin >> l;
			c.insert(l);
		}

		int i = 0, j = 0;
		while (i < q.size())
			if (c.count(a[q[i]]))
				i++;
			else
				break;

		if (i == q.size()) {
			cout << "0 0" << endl;
			continue;
		}

		j = i+1;
		while (j < q.size())
			if (c.count(a[q[j]]))
				j++;
			else
				break;

		cout << a[q[i]] << " ";
		if (j == q.size())
			cout << b[*pos[a[q[i]]].begin()] << endl;
		else
			cout << b[*lower_bound(ALL(pos[a[q[i]]]), q[j])] << endl;
	}

	return 0;
}