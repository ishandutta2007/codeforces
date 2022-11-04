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
typedef vector<ii> vii;

const int MX = 505;
int n, a[MX];
multiset<int> st;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n * n; i++) {
		int a;
		cin >> a;
		st.insert(a);
	}

	for (int i = 0; i < n; i++) {
		a[i] = *st.rbegin();
		st.erase(st.find(a[i]));

		for (int j = 0; j < i; j++) {
			int g = __gcd(a[i], a[j]);
			st.erase(st.find(g));
			st.erase(st.find(g));
		}
	}

	forn (i, n) cout << a[i] << " ";
	cout << endl;

	return 0;
}