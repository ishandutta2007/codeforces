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
	
	int n, a, b;

	cin >> n >> a >> b;

	a--;
	a += b;

	a %= n;
	a += n;
	a %= n;

	cout << a + 1 << endl;

	return 0;
}