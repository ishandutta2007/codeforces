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

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);

	string a, b, res;
	int c[10], i, y;
	fill(c, c+10, 0);

	cin >> a >> b;

	if (a.size() < b.size()) {
		sort(a.begin(), a.end(), greater<int>());
		cout << a << endl;
		return 0;
	}

	for (char h : a)
		c[h-'0']++;

	while (c[b[i]-'0']) {
		c[b[i]-'0']--;
		res.push_back(b[i]);

		string aux;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < c[j]; k++) {
				aux.push_back(j+'0');
			}
		}

		if (res + aux > b) {
			res.pop_back();
			c[b[i]-'0']++;
			break;
		}

		i++;
	}

	if (i < b.size()) {
		for (int j = b[i]-'0'-1; j >= 0; j--) {
			if (c[j]) {
				res.push_back(j+'0');
				c[j]--;
				break;
			}
		}
		i++;
	}

	for (int j = 9; j >= 0; j--) {
		while (c[j]) {
			res.push_back(j+'0');
			c[j]--;
		}
	}

	cout << res << endl;

	return 0;
}