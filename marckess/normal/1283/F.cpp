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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005;
int n, a[MX], p[MX], mx[MX], cn[MX];
set<ii> st;

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

int join (int a, int b) {
	mx[parent(a)] = max(mx[parent(a)], mx[parent(b)]);
	p[parent(b)] = parent(a);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn(i, n) st.emplace(i+1, i+1);

	for (int i = 1; i < n; i++) {
		cin >> a[i];
		st.erase(ii(a[i], a[i]));
		cn[a[i]]++;
	}

	iota(p, p+MX, 0);
	iota(mx, mx+MX, 0);

	cout << a[1] << endl;
	for (int i = n - 1; i; i--) {
		cout << a[i] << " " << st.begin()->se << endl;
		join(a[i], st.begin()->se);
		cn[a[i]]--;
		st.erase(st.begin());
		if (!cn[a[i]])
			st.emplace(mx[parent(a[i])], a[i]);
	}

	return 0;
}