#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, k, a[105];

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a+n, greater<int>());

	for (int i = 0; i < n; i++)
		if (k % a[i] == 0) {
			cout << k / a[i] << endl;
			return 0;
		}

	return 0;
}