#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, bs[MX];
vi m2;
vii res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	
	for (int i = 3; i <= n; i += 2)
		if (!bs[i]) {
			vi v;
			
			for (int j = i; j <= n; j += i)
				if (!bs[j]) {
					bs[j] = 1;
					v.pb(j);
				}
			
			if (v.size() == 1) continue;
			
			if (v.size() & 1) {
				res.emplace_back(v[0], v[2]);
				m2.pb(v[1]);
				
				for (int j = 3; j < v.size(); j += 2)
					res.emplace_back(v[j], v[j + 1]);
			} else {
				for (int j = 0; j < v.size(); j += 2)
					res.emplace_back(v[j], v[j + 1]);
			}
		}
	
	for (int i = 2; i <= n; i += 2)
		if (!bs[i]) {
			bs[i] = 1;
			m2.pb(i);
		}
	
	for (int i = 0; i + 1 < m2.size(); i += 2)
		res.emplace_back(m2[i], m2[i + 1]);
	
	cout << res.size() << endl;
	for (ii p : res)
		cout << p.fi << " " << p.se << endl;
	
	return 0;
}