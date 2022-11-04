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
int n, a[MX], b[MX], ex[MX];
set<int> st[MX];

void main_() {
	cin >> n;
	
	forn (i, n + 1) {
		st[i].clear();
		ex[i] = 1;
	}
	
	forn (i, n) cin >> a[i];
	
	queue<ii> q;
	forn (i, n) {
		cin >> b[i];
		q.emplace(b[i], i);
	}
	
	forn (i, n - 1)
		if (b[i] == b[i + 1])
			st[b[i]].insert(i + 1);
	
	forn (i, n - 1) {
		while (!ex[q.front().se])
			q.pop();
		
		if (q.front().fi == a[i]) {
			q.pop();
		} else {
			auto it = st[a[i]].upper_bound(q.front().se);
			
			if (it == st[a[i]].end()) {
				cout << "NO" << endl;
				return;
			}
			
			ex[*it] = 0;
			st[a[i]].erase(it);
		}
	}
	
	cout << "YES" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}