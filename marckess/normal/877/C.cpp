#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define first fi
#define second se
#define SET(p,n) memset(p, n, sizeof(p));

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	cout << (n / 2) * 2 + (n+1) / 2 << endl;
	for (int i = 2; i <= n; i += 2)
		cout << i << " ";
	for (int i = 1; i <= n; i += 2)
		cout << i << " ";
	for (int i = 2; i <= n; i += 2)
		cout << i << " ";
	cout << endl;

	return 0;
}