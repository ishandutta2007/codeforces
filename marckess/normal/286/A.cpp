#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int n, a[100005];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	
	if (n % 4 >= 2) {
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0, j = 2; j <= n / 2; i+=2, j += 2)
		a[i] = j;
	for (int i = 1, j = n; j > n / 2; i+=2, j -= 2)
		a[i] = j;
	for (int i = n-1, j = n-1; j > n / 2; i-=2, j -= 2)
		a[i] = j;
	for (int i = n-2, j = 1; j < n / 2; i-=2, j += 2)
		a[i] = j;

	if (n & 1) a[n/2]=n/2+1;
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;

	return 0;
}