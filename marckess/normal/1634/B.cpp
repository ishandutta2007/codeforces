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

const int MX = 100005;
ll n, x, y, a[MX];

void main_() {
	cin >> n >> x >> y;
	forn (i, n)
		cin >> a[i];
		
	set<int> st;
	st.insert(x % 4);
	
	forn (i, n) {
		set<int> nex;
		for (int d : st) {
			nex.insert((d + a[i]) % 4);
			nex.insert((d ^ a[i]) % 4);
		}
		st = nex;
	}
	
	if (st.count(y % 4)) cout << "Alice" << endl;
	else cout << "Bob" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}