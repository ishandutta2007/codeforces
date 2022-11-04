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

const int MX = 1000005;
int n, a[2*MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 2; i < n+2; i++)
		a[i] = i - 1;

	for (int i = 2; i <= n; i++) {
		int j = i, temp = 0;
		while (j < n + i) {
			swap(a[j], temp);
			j += i;
		}
		a[n+i] = temp;
	}

	for (int i = n+1; i <= 2*n; i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}