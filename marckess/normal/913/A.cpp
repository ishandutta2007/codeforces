#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	ll n, m, x = 1;

	cin >> n >> m;

	while (x <= m && n) {
		x *= 2;
		n--;
	}

	if (x <= m)
		cout << m % x << endl;
	else
		cout << m << endl;

	return 0;
}