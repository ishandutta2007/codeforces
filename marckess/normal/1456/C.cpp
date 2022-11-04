#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 500005;
int n, k;
ll res, s = 0, izq, der, c[MX], cn[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	forn (i, n) cin >> c[i];
	sort (c, c + n, greater<ll>());
	
	forn (i, n) {
		s += c[i];
		izq += (n - 1 - i) * c[i];
	}
	res = izq;
	
	for (int i = n - 1, j = 0; i >= 0; i--) {
		s -= c[i];
		
		if (j == k) {
			j = 0;
			cn[k]++;
			continue;
		}
		
		izq -= c[i] * cn[k];
		
		izq -= s;
		der += c[i] * cn[j];
		cn[j]++;
		j++;
		
		res = max(res, izq + der);
	}
	
	cout << res << endl;
	
	return 0;
}