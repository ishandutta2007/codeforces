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
int n, ft[MX];
queue<int> q[256];
string s, t;

void update (int i, int k) {
	i++;
	
	while (i < MX) {
		ft[i] += k;
		i += i & -i;
	}
}

int query (int i) {
	i++;
	
	int s = 0;
	while (i) {
		s += ft[i];
		i -= i & -i;
	}
	
	return s;
}

ll cost (int i, char c) {
	if (q[c].empty()) return 1e18;
	ll p = q[c].front() + query(q[c].front());
	return abs(p - i);
}

void main_() {
	cin >> n >> s >> t;
	
	forn (i, n + 5)
		ft[i] = 0;
	forn (i, 256)
		while (q[i].size())
			q[i].pop();
	
	forn (i, n)
		q[s[i]].push(i);
	
	ll acu = 0, res = 1e18;
	
	forn (i, n) {
		for (int c = 'a'; c < t[i]; c++)
			res = min(res, acu + cost(i, c));
		
		if (q[t[i]].empty())
			break;
		
		acu += cost(i, t[i]);
		
		update(0, 1);
		update(q[t[i]].front(), -1);
		q[t[i]].pop();
	}
	
	if (res == 1e18) cout << -1 << endl;
	else cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}