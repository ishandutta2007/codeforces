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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, k, l[MX], off[MX], us[MX];
priority_queue<ii, vii, greater<ii>> pq;

void insert (int i) {
	if (l[i] == us[i]) return;
	pq.emplace(off[i] + (us[i] + 1) / 2, i);
}

bool esPos (int m) {
	ll acu = 1;
	
	for (int i = 0; i < n && off[i] < m; i++) {
		acu--;
		acu += min(l[i] - 1, 2 * (m - off[i]));
		if (acu >= k) return 1;
	}
	
	return 0;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	forn (i, n)
		cin >> l[i];
	sort (l, l + n, greater<int>());
	
	off[0] = 1;
	us[0] = 1;
	insert(0);
	
	for (int i = 1; i < n; i++) {
		int u = pq.top().se;
		int d = pq.top().fi;
		pq.pop();
		
		off[i] = d + 1;
		us[i] = 1;
		insert(i);
		
		us[u]++;
		insert(u);
	}
	
	int i = 1, j = 1e6, rep = 20;
	
	while (rep--) {
		int m = (i + j) / 2;
		if (esPos(m)) j = m;
		else i = m;
	}
	
	if (j == 1e6) cout << -1 << endl;
	else cout << j << endl;
	
	return 0;
}