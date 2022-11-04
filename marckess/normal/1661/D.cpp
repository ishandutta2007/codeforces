// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005;
int n, k;
ll a[MX], b[MX], d[MX];

void main_() {
	cin >> n >> k; 
	forn (i, n)
		cin >> b[i];
	
	ll res = 0;
	for (int i = n - 1; i >= k; i--) {
		a[i] = a[i + 1];
		d[i] += d[i + 1];
		a[i] += d[i];
		
		if (a[i] >= b[i]) continue;
		
		ll p = (b[i] - a[i] + k - 1) / k;
		res += p;
		
		a[i] += p * k;
		d[i] -= p;	
		if (i - k - 1 >= 0)
			d[i - k - 1] += p;
	}
	
	ll mx = 0;
	for (int i = k - 1; i >= 0; i--) {
		a[i] = a[i + 1];
		d[i] += d[i + 1];
		a[i] += d[i];
		
		if (a[i] >= b[i]) continue;
		
		ll p = (b[i] - a[i] + (i + 1) - 1) / (i + 1);
		mx = max(mx, p);
	}
	
	cout << res + mx << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}