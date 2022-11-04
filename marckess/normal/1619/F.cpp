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

const int MX = 200005;
int n, m, k;

void main_() {
	cin >> n >> m >> k;
	
	priority_queue<ii, vii, greater<ii>> pq;
	
	forn (i, n)
		pq.push({0, i});
	
	forn (kk, k) {
		vii v;
		
		forn (j, m) {
			cout << n / m + int(j < n % m);
			
			forn (l, n / m + int(j < n % m)) {
				int cn = pq.top().fi;
				int i = pq.top().se;
				pq.pop();
				
				cout << " " << i + 1;
				v.pb({cn + int(j < n % m), i});
			}
			cout << endl;
		}
		
		for (ii &p : v)
			pq.push(p);
	}
	
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}