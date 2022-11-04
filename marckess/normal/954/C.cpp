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

const int MX = 200005;
int n, a[MX], y = -1;

void no () {
	cout << "NO" << endl;
	exit(0);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i && a[i] == a[i-1]) no();
		if (i && abs(a[i]-a[i-1]) != 1) y = abs(a[i]-a[i-1]); 
	}

	if (y == -1) y = 1e9;

	int i = (a[0] - 1) / y + 1;
	int j = (a[0] - 1) % y + 1;
	int b = a[0];

	for (int k = 1; k < n; k++) {
		if (a[k] == b + 1) {
			j++;
			if (y != -1 && j > y) no();
		} else if (a[k] == b - 1) {
			j--;
			if (j < 1) no();
		} else if (abs(a[k]-b) != y) {
			no();
		} else if (a[k] > b) {
			i++;
		} else if (a[k] < b) {
			i--;
			if (i < 1) no();
		}
		b = a[k];
	}

	cout << "YES" << endl;
	cout << int(1e9) << " " << y << endl;

	return 0;
}