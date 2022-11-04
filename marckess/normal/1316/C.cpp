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

const int MX = 1000005;
int n, m, p, a[MX], b[MX], x, y;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	scanf("%d%d%d", &n, &m, &p);

	forn (i, n) scanf("%d", a+i);
	forn (i, m) scanf("%d", b+i);

	forn (i, n) {
		if (a[i] % p) {
			x = i;
			break;
		}
	}

	forn (i, m) {
		if (b[i] % p) {
			y = i;
			break;
		}
	}

	printf("%d\n", x + y);

	return 0;
}