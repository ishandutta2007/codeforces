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
typedef vector<ll> vi;
typedef vector<ii> vii;

const int MX = 105, lim = 300000;
int n, p[MX], k[MX];
ld q[MX], act = 1, res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		q[i] = 1 - p[i] / 100.0l;
		act *= 1 - q[i];
		k[i] = 1;
	}

	for (int i = n + 1; i <= lim; i++) {
		res += act;

		ld mx = act / (1 - pow(q[0], k[0])) * (1 - pow(q[0], k[0] + 1));
		int ind = 0;

		for (int j = 1; j < n; j++) {
			ld p = act / (1 - pow(q[j], k[j])) * (1 - pow(q[j], k[j] + 1));
			if (p > mx) {
				mx = p;
				ind = j;
			}
		}

		act = mx;
		k[ind]++;
	}

	cout << fixed << setprecision(10) << lim * act - res << endl;

	return 0;
}