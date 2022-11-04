#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j ) )
#define LSB(S) (S & (-S))

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	vector<string> s;
	string res(2e6+5, 'a');
	int n, k, a, ind = 1;
	vii v;

	cin >> n;
	s = vector<string>(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> k;
		while (k--) {
			cin >> a;
			v.emplace_back(a, i);
		}
	}

	sort (v.begin(), v.end());
	for (int i = 0, j; i < v.size(); i++) {
		tie(a, j) = v[i];
		for (ind = max(ind, a); ind < a + s[j].size(); ind++)
			res[ind] = s[j][ind-a];
	}

	for (int i = 1; i < ind; i++)
		cout << res[i];
	cout << endl;

	return 0;
}