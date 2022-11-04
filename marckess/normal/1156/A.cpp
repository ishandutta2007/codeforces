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

int n, a[105], res = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = n - 1; i >= 0; i--)
		cin >> a[i];

	for (int i = 1; i < n; i++) {
		if (a[i] == 2 && a[i-1] == 3) {
			cout << "Infinite" << endl;
			return 0;
		} 
		if (a[i] == 3 && a[i-1] == 2) {
			cout << "Infinite" << endl;
			return 0;
		}
	}

	for (int i = 0; i + 1 < n; i++) {
		if (a[i] == 1) res += 3 + int(a[i+1] == 3);
		else if (a[i] == 2) res += 3;
		else res += 4;
	}

	for (int i = 1; i + 1 < n; i++) {
		if (a[i] == 1 && a[i-1] == 2 && a[i+1] == 3)
			res--;
	}

	cout << "Finite" << endl;
	cout << res << endl;

	return 0;
}