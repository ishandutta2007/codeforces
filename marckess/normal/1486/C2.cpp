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

int n;
	
int query (int l, int r) {
	if (l == r) return -1;
	cout << "? " << l << " " << r << endl;
	int res;
	cin >> res;
	return res;
}

void ans (int p) {
	cout << "! " << p << endl;
	exit(0);
}

void der (int p) {
	int i = p + 1, j = n, rep = 18;
	while (rep--) {
		int m = (i + j) / 2;
		if (query(p, m) == p) j = m;
		else i = m;
	}
	ans(j);
}

void izq (int p) {
	int i = 1, j = p - 1, rep = 18;
	while (rep--) {
		int m = (i + j + 1) / 2;
		if (query(m, p) == p) i = m;
		else j = m;
	}
	ans(i);
}

int main () {
	// ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	
	int p = query(1, n);
	int ot = query(p, n);
	
	if (ot == p) der(p);
	else izq(p);
	
	return 0;
}