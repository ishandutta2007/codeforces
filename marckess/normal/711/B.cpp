#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int n, a[505][505], x, y;
ll sum = -1, ot = -1;

bool checar (ll &a, ll &b) {
	if (a == -1)
		a = b;
	else if (a != b) {
		cout << -1 << endl;
		return 1;
	}

	return 0;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    	for (int j = 0; j < n; j++) {
    		cin >> a[i][j];
    		if (!a[i][j])
    			x = i, y = j;
    	}

    for (int i = 0; i < n; i++) {
		ll acu = 0;

		for (int j = 0; j < n; j++)
			acu += a[i][j];
		
		if (i == x) {
			if (checar(ot, acu))
				return 0;
		} else {
			if (checar(sum, acu))
				return 0;
		}
    }

    for (int j = 0; j < n; j++) {
    	ll acu = 0;

    	for (int i = 0; i < n; i++)
    		acu += a[i][j];

    	if (j == y) {
			if (checar(ot, acu))
				return 0;
		} else {
			if (checar(sum, acu))
				return 0;
		}
    }

    ll acu = 0;
    for (int i = 0; i < n; i++)
    	acu += a[i][i];

    if (x == y) {
		if (checar(ot, acu))
			return 0;
	} else {
		if (checar(sum, acu))
			return 0;
	}

   	acu = 0;
   	for (int i = 0; i < n; i++)
   		acu += a[i][n-i-1];

   	if (x == n-y-1) {
		if (checar(ot, acu))
			return 0;
	} else {
		if (checar(sum, acu))
			return 0;
	}

   	if (sum == -1)
   		cout << 1 << endl;
   	else if (ot < sum)
   		cout << sum - ot << endl;
   	else
   		cout << -1 << endl;

    return 0;
}