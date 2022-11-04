#include <bits/stdc++.h>

// #define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
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

int query (int a, int b) {
	cout << "? " << a << " " << b << endl;
	int res;
	cin >> res;
	if (res == -1)
		exit(0);
	return res;
}

void vic (vi &v, int a, int b) {
	if (query(a, b) == 1)
		v.pb(a);
	else
		v.pb(b);
}

vi go (vi v) {
	vi res;
	
	if (v.size() == 2) {
		vic(res, v[0], v[1]);
		return res;
	}
	
	for (int i = 0; i < v.size(); i += 4) {
		int r = query(v[i], v[i + 2]);
		
		if (r == 0) {
			vic(res, v[i + 1], v[i + 3]);
		} else if (r == 1) {
			vic(res, v[i], v[i + 3]);
		} else {
			vic(res, v[i + 1], v[i + 2]);
		}
	}
	
	return res;
}

void main_() {
	int n;
	cin >> n;
	
	vi v(1 << n);
	iota(all(v), 1);
	
	while (v.size() > 1) {
		v = go(v);
	}
	
	cout << "! " << v[0] << endl;
}

int main() {
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}