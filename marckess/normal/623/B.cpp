#include <bits/stdc++.h>
 
#define endl '\n'
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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MX = 1000005;
int n, x[MX];
ll a, b, res, izq[MX], der[MX];
set<int> st;

void fac (int n) {
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) {
			st.insert(i);
			while (n % i == 0)
				n /= i;
		}

	if (n > 1)
		st.insert(n);
}

void go (int k) {
	ll acu = a * n;
	
	for (int i = 0; i < n; i++) {
		int r = x[i] % k;
		
		if (r == 0) {
			acu += -a;
		} else if (r == 1 || r == k - 1) {
			acu += -a + b;
		} else {
			acu = 1e18;
		}

		izq[i] = acu - a * n;
		res = min(res, acu);
	}

	acu = a * n;
	for (int i = n - 1; i >= 0; i--) {
		int r = x[i] % k;
		
		if (r == 0) {
			acu += -a;
		} else if (r == 1 || r == k - 1) {
			acu += -a + b;
		} else {
			acu = 1e18;
		}

		der[i] = acu - a * n;
		res = min(res, acu);
	}

	ll mn = der[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		res = min(res, a * n + izq[i] + mn);
		mn = min(mn, der[i]);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++)
		cin >> x[i];

	fac(x[0]);
	fac(x[0] - 1);
	fac(x[0] + 1);

	fac(x[n - 1]);
	fac(x[n - 1] - 1);
	fac(x[n - 1] + 1);

	res = a * (n - 1);
	for (int k : st)
		go(k);
	cout << res << endl;

	return 0;
}