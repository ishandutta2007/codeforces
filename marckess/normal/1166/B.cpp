#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int k, x = -1, y = -1;
	string vo = "aeiou";

	cin >> k;
	for (int i = 5; i < k; i++)
		if (k % i == 0 && k / i >= 5)
			x = i, y = k / i;

	if (x == -1) {
		cout << x << endl;
		return 0;
	}

	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			cout << vo[(j+i%5)%5];
	cout << endl;

	return 0;
}