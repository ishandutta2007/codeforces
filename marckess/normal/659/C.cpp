#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, m, a;
	bitset<10000000> bs;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a < 1e7)
			bs[a] = 1;
	}
	
	stack<int> res;
	int i = 1;
	while (m - i >= 0) {
		while (bs[i])
			i++;
		if (m - i >= 0) {
			res.push(i);
			m -= i;
			bs[i] = 1;
		}
	}

	cout << res.size() << endl;
	while (res.size()) {
		cout << res.top() << " ";
		res.pop();
	}
	cout << endl;

	return 0;
}