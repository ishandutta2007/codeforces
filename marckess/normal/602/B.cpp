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
typedef vector<vvi> vvvi;

struct SW {
	deque<ii> d;
	bool comp; // 1 : <, 0 : >

	SW (bool c) : comp(c) {}

	void push (int x, int i) {
		while (d.size() && (d.back().fi < x ^ comp))
			d.pop_back();
		d.emplace_back(x, i);
	}

	int query (int i) {
		while (d.size() && d.front().se < i)
			d.pop_front();
		return d.front().fi;
	}
};

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, a[100005];

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int i = 0, j = 0, res = 0;
	SW mx(0), mn(1); 

	while (j < n) {
		mn.push(a[j], j);
		mx.push(a[j], j);

		while (mx.query(i) - mn.query(i) > 1)
			i++;

		res = max(res, j-i+1);
		j++;
	}

	cout << res << endl;

	return 0;
}