#include <bits/stdc++.h>
 
//#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MX = 5005;
int n, m;
ll s;
int a[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;

	int i;
	for (i = 0; i < n && m > 0; i++) {
		a[i] = i + 1;
		m -= i / 2;
	}
	if (i) a[i - 1] += -2 * m;

	if (m > 0) {
		cout << -1 << endl;
		return 0;
	}

	if (!i) {
		a[0] = 1;
		s = 2;
		i++;
	} else {
		s = a[i - 1] + 1;
	}

	while (i < n) {
		a[i] = a[i - 1] + s;
		i++;
	}

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}