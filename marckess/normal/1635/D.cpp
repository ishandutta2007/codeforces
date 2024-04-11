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

const int MX = 200005, mod = 1000000007;
int n, p, a[MX], f[MX];
set<int> st;
 
bool valid (int x) {
	while (x) {
		if (x & 1) {
			x /= 2;
		} else if (!(x & 3)) {
			x /= 4;
		} else {
			return 1;
		}
		
		if (st.count(x))
			return 0;
	}
	
	return 1;
}
 
void main_() {
	cin >> n >> p;
	
	forn (i, n) {
		cin >> a[i];
		st.insert(a[i]);
	}
	
	ll res = 0;
	forn (i, n)
		if (valid(a[i])) {
			int j = 0;
			forn (k, 30)
				if (a[i] & (1 << k))
					j = k + 1;
			
			if (j <= p)
				(res += f[p - j]) %= mod; 
		}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	f[0] = f[1] = 1;
	for (int i = 2; i < MX; i++)
		f[i] = (f[i - 1] + f[i - 2]) % mod;
	
	for (int i = 1; i < MX; i++)
		(f[i] += f[i - 1]) %= mod;
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}