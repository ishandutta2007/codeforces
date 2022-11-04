#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
#define MOD(n,k) ((((n) % (k)) + (k)) % (k))
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, x, a;
	bitset<105> bs;

	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> a;
		bs[a] = 1;
	}

	int res = 0;
	for (int k = 0; k < x; k++)
		if (!bs[k])
			res++;

	if (bs[x])
		cout << res + 1 << endl;
	else
		cout << res << endl;

	return 0;
}