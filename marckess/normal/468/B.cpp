#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, a, b, p[MX], v[MX], cn[MX], x[MX], y[MX];
map<int, int> mp;
vi res;

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

void join (int a, int b) {
	a = parent(a), b = parent(b);
	if (a == b) return;
	p[a] = b;
	cn[b] += cn[a];
	x[b] += x[a];
	y[b] += y[a];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> a >> b;
	
	forn (i, n) {
		cin >> v[i];
		mp[v[i]] = i;
		p[i] = i;
		cn[i] = 1;
	}
	
	forn (i, n) {
		if (mp.count(a - v[i])) {
			join(i, mp[a - v[i]]);
			x[parent(i)]++;
		}
		
		if (mp.count(b - v[i])) {
			join(i, mp[b - v[i]]);
			y[parent(i)]++;
		}
	}
	
	forn (i, n) {
		if (cn[parent(i)] == x[parent(i)]) res.pb(0);
		else if (cn[parent(i)] == y[parent(i)]) res.pb(1);
		else {
			cout << "NO" << endl;
			return 0;
		}
	}
	
	cout << "YES" << endl;
	for (int r : res) cout << r << " ";
	cout << endl;
	
	return 0;
}