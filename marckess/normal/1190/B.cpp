#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;
int n, a[MX], f = 0;

void fi() { cout << "sjfnb" << endl; exit(0); }
void se() { cout << "cslnb" << endl; exit(0); }

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a+n);

	if (!a[n-1]) se();

	for (int i = 0; i < n; i++) {
		if (i < n - 1 && a[i] == a[i+1]) {
			if (!a[i]) se();
			a[i]--;
			f++;
			if (i && a[i] == a[i-1]) se();
		}
	}

	if (f > 1) se();
	ll s = 0;
	for (int i = 0; i < n; i++)
		s += a[i] - i;

	if (f ^ (s & 1)) fi();
	else se();

	return 0;
}