#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int k, a, b;
	cin >> k >> a >> b;

	if (a < k && b && b % k == 0) 
		cout << b / k << endl;
	else if (b < k && a && a % k == 0) 
		cout << a / k << endl;
	else if (a >= k && b >= k) 
		cout << a / k + b / k << endl;
	else
		cout << -1 << endl;

	return 0;
}