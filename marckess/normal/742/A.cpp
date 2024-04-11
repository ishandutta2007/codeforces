#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define fill_to_n(a,n,k) iota(a,a+n,k)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int pot (int b, int p, int m) {
	int res = 1;
	b %= m;

	while (p) {
		if (p & 1) {
			res *= b;
			res %= m;
		}

		b *= b;
		b %= m;
		p /= 2;
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;

	cin >> n;
	cout << pot(1378, n, 10) << endl;

	return 0;
}