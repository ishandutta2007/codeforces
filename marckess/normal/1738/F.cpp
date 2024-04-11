#include <bits/stdc++.h>

//#define endl '\n'
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

const int MX = 1005;
int n, d[MX], p[MX];
vii pos;

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

void join (int a, int b) {
	p[parent(a)] = parent(b);
}

void main_() {
	cin >> n;
	pos.clear();
	forr (i, 1, n) {
		cin >> d[i];
		pos.pb({d[i], i});
	}
	
	sort(all(pos), greater<ii>());
	memset(p, 0, sizeof(p));
	
	for (auto [d, u] : pos) {
		if (p[u]) continue;
		p[u] = u;
		
		forn (i, d) {
			cout << "? " << u << endl;
			int v;
			cin >> v;
			
			if (p[v]) {
				join(u, v);
				break;
			} else {
				p[v] = v;
				join(u, v);
			}
		}
	}
	
	cout << "!";
	forr (i, 1, n) 
		cout << " " << parent(i);
	cout << endl;
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}