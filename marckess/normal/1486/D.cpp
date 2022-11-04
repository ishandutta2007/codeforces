#include <bits/stdc++.h>

// #define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, k, a[MX], acu[MX];

bool esPos (int m) {
	int s = 0, mn = 1e9;
	
	for (int i = 1; i <= n; i++) {
		if (a[i] >= m) s++;
		else s--;
		acu[i] = s;
		
		if (i - k >= 0)
			mn = min(mn, acu[i - k]);
		
		if (s - mn > 0)
			return 1;
	}
	
	return 0;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	int i = 1, j = n, rep = 20;
	while (rep--) {
		int m = (i + j + 1) / 2;
		if (esPos(m)) i = m;
		else j = m;
	}
	cout << i << endl;
	
	return 0;
}