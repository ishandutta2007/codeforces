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

int p[155][155];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 	
	SET(p[0], 0);
	SET(p[1], 0);
	p[1][0] = 1;

	int n;
	cin >> n;

	for (int i = 2; i <= n + 1; i++) {
		p[i][0] = p[i-2][0];
		for (int j = 1; j <= 150; j++)
			p[i][j] = (p[i-1][j-1] + p[i-2][j]) % 2;
	}

	cout << n << endl;
	for (int i = 0; i <= n; i++)
		cout << p[n+1][i] << " ";
	cout << endl;

	cout << n - 1 << endl;
	for (int i = 0; i < n; i++)
		cout << p[n][i] << " ";
	cout << endl;

	return 0;
}