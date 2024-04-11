#include <bits/stdc++.h>

//#define endl '\n'
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

int a[] = {4, 8, 15, 16, 23, 42};
vi b(4);

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	for (int i = 0; i < 4; i++) {
		cout << "? 1 " << i + 2 << endl;
		cin >> b[i];
	}

	do {
		vi c(4);
		for (int i = 0; i < 4; i++)
			c[i] = a[0] * a[i+1];
		if (b == c) {
			cout << "!";
			for (int i = 0; i < 6; i++)
				cout << " " << a[i];
			cout << endl;
			return 0;
		}
	} while (next_permutation(a, a+6));

	return 0;
}