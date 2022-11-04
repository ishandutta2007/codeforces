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

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	string s;

	cin >> s >> s;

	string res(s.size(), 0);

	int i = 0, f = s.size() - 1;
	bool t = 0;
	for (int j = s.size() - 1; j >= 0; j--) {
		if (t)
			res[i++] = s[j];
		else
			res[f--] = s[j];
		t = !t;
	}

	cout << res << endl;

	return 0;
}