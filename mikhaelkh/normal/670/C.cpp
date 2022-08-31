#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

map<int,int> v;
int const N = 200010;

int n, m, a[N], b[N], c[N];

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		v[a[i]]++;
	}
	cin >> m;
	for (int i=0; i<m; ++i)
		cin >> b[i];
	for (int i=0; i<m; ++i)
		cin >> c[i];
	pair<int,int> r = make_pair(-1,-1);
	int ri = 0;
	for (int i=0; i<m; ++i)
		if (r < make_pair(v[b[i]], v[c[i]]))
			r = make_pair(v[b[i]], v[c[i]]), ri = i;
	cout << ri+1 << endl;
	return 0;
}