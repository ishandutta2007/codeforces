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

const int MX = 100005, mod = 1000000007;
int n, a[MX], b[MX], p[MX], f[MX], d[MX];
ll res;

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

void join (int a, int b) {
	p[parent(a)] = parent(b);
}

void main_() {
	cin >> n;
	
	forr (i, 1, n) {
		p[i] = i;
		f[i] = 0;
	}
	
	forr (i, 1, n) {
		cin >> a[i];
	}
	
	forr (i, 1, n) {
		cin >> b[i];
		join(a[i], b[i]);
	}
	
	forr (i, 1, n) {
		cin >> d[i];
		f[parent(d[i])] = 1;
	}
	
	forr (i, 1, n)
		if (a[i] == b[i])
			f[a[i]] = 1;
	
	res = 1;
	forr (i, 1, n)
		if (i == parent(i) && !f[i])
			(res *= 2) %= mod;
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}