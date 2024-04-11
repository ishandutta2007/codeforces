#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

int n;

void impr (int i, char c, int j, int res) {
	cout << i << " " << c << " " << j << " = " << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	if (n < 4) {
		cout << "NO" << endl;
		return 0;
	}
	
	cout << "YES" << endl;
	if (n % 2) {
		for (int i = 6; i <= n; i += 2) {
			impr(i + 1, '-', i, 1);
			impr(1, '*', 1, 1);
		}
		impr(2, '+', 3, 5);
		impr(5, '*', 4, 20);
		impr(20, '+', 5, 25);
		impr(25, '-', 1, 24);
	} else {
		for (int i = 5; i <= n; i += 2) {
			impr(i + 1, '-', i, 1);
			impr(1, '*', 1, 1);
		}
		impr(1, '*', 2, 2);
		impr(2, '*', 3, 6);
		impr(6, '*', 4, 24);
	}
	
	return 0;
}