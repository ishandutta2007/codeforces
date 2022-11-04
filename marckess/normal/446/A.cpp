#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

#define find(v,x) (lower_bound(ALL(v),x))

const int MX = 100005;
int n, a[MX], ant[MX], sig[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	a[0] = 2e9;
	for (int i = 1; i <= n; i++) {
		if (a[i] <= a[i-1]) ant[i] = i-1;
		else ant[i] = ant[i-1];
	}

	a[n+1] = -2e9;
	for (int i = n; i > 0; i--) {
		if (a[i] >= a[i+1]) sig[i] = i+1;
		else sig[i] = sig[i+1];
	}

	//for (int i = 1; i <= n; i++)
	//	cout << ant[i] << " " << sig[i] << endl;

	a[0] = 2e9, ant[0] = 0;
	a[n+1] = -2e9, sig[n+1] = n+1;

	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i-1] <= a[i+1]-2){
			res = max(res, sig[i+1] - ant[i-1] - 1);
		} else {
			res = max({res, sig[i+1]-i, i-ant[i-1]});
		}
	}

	cout << res << endl;

	return 0;
}