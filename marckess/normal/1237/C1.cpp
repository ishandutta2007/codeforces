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

const int MX = 2005;
int n, x[MX], y[MX], z[MX];
set<int> st;

int dis (int i, int j) {
	return abs(x[i] - x[j]) + abs(y[i] - y[j]) + abs(z[i] - z[j]);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> z[i];
		st.insert(i);
	}

	for (int kk = 0; kk < n / 2; kk++) {
		int i = *st.begin();
		st.erase(st.begin());
		int j = *st.begin();

		for (int x : st)
			if (dis(i, j) > dis(i, x))
				j = x;

		cout << i+1 << " " << j+1 << endl;
		st.erase(j);
	}

	return 0;
}