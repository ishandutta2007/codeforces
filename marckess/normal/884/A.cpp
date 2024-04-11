#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, t, a[105];

	cin >> n >> t;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int res = 0, i = 0;
	while (t > 0) {
		t -= 86400 - a[i++];
		res++;
	}

	cout << res << endl;

	return 0;
}