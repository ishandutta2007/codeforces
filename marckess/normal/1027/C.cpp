#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 1000005;
int t, n, acu[MX], a[MX];
ll ra, rb;
vi v;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> t;
	while (t--) {
		v.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			acu[a[i]]++;
		}

		for (int i = 0; i < n; i++) {
			acu[a[i]] /= 2;
			while (acu[a[i]]--)
				v.pb(a[i]);
			acu[a[i]] = 0;
		}

		sort(ALL(v));
		ra = v[0], rb = v[1];
		for (int i = 1; i < (int)v.size()-1; i++) {
			ll a = v[i];
			ll b = v[i+1];
			if ((ra*ra+rb*rb)*a*b > (a*a+b*b)*ra*rb) {
				ra = a;
				rb = b;
			}
		}

		cout << ra << " " << ra << " " << rb << " " << rb << endl;
	}

	return 0;
}