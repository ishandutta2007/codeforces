#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	int n, m, v[1005], a, b;

	cin >> n >> m;

	v[0] = 1;
	while (n--) {
		cin >> a >> b;

		if (!v[a])
			continue;

		for (int i = a; i <= b; i++)
			v[i] = 1;
	}

	if (v[m])
		cout << "YES" << endl;
	else
		cout << "no" << endl;

	return 0;
}