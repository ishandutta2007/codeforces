#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n;
string a;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> a;
	n = a.size();
	a.pb('b');

	for (int i = 0; i < n; i++) {
		if (a[i] != a[i+1]) {
			cout << 1 << " ";
		} else {
			cout << 0 << " ";
		}
	}
	cout << endl;

	return 0;
}