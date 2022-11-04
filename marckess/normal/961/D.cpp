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

int n, x[100005], y[100005];

bool collinear (int a, int b, int c) {
	ll x1 = x[a] - x[b];
	ll x2 = x[a] - x[c];
	ll y1 = y[a] - y[b];
	ll y2 = y[a] - y[c];

	return x1 * y2 - x2 * y1 == 0;
}

bool obtRes (int a1, int a2) {
	int b1 = -1, b2 = -1;

	for (int i = 0; i < n; i++) {
		if (a1 == i || a2 == i)
			continue;

		if (collinear(a1, a2, i))
			continue;

		if (b1 == -1)
			b1 = i;
		else if (b2 == -1)
			b2 = i;
		else if (!collinear(b1, b2, i))
			return 0;
	}

	return 1;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    	cin >> x[i] >> y[i];

    if (n < 4) {
    	cout << "YES" << endl;
    	return 0;
    }

    if (obtRes(0, 1) || obtRes(0, 2) || obtRes(1, 2))
    	cout << "YES" << endl;
    else
    	cout << "NO" << endl;

    return 0;
}