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

struct Punto {
	int x, y, z, ind;
	
	Punto () {}
	Punto (int x, int y, int z, int ind) : x(x), y(y), z(z), ind(ind) {}

	bool operator < (const Punto &ot) const {
		if (x != ot.x) return x < ot.x;
		if (y != ot.y) return y < ot.y;
		return z < ot.z;
	}
};

int n;
set<Punto> st;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		st.emplace(x, y, z, i);
	}

	for (int kk = 0; kk < n / 2; kk++) {
		Punto i = *st.begin();
		st.erase(i);

		Punto j = *st.begin();
		j.y = i.y;
		j.z = -1e9;

		auto aux = st.lower_bound(j);
		if (aux == st.end() || aux->x != j.x)
			aux--;

		j = *aux;
		j.z = i.z;

		aux = st.lower_bound(j);
		if (aux == st.end() || aux->x != j.x || aux->y != j.y)
			aux--;

		j = *aux;

		cout << i.ind << " " << j.ind << endl;
		st.erase(j);
	}

	return 0;
}