#include <bits/stdc++.h>

#define endl '\n'
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

const int MX = 100005, SIG = 26;
int nex[MX][SIG], fail[MX], out[MX], finish[MX], cnt[MX], sz = 1;

void insert (string &s, int ind, int cost) {
	int u = 0;

	for (char c : s) {
		c -= 'a';

		if (!nex[u][c]) {
			nex[u][c] = sz;
			finish[sz] = -1;
			sz++;
		}

		u = nex[u][c];
	}

	finish[u] = ind;
	cnt[u] += cost;
}

int memf[MX][SIG];
int getFail (int u, int c) {
	int &res = memf[u][c];
	if (memf[u][c] != -1)
		return res;
		
	if (u && !nex[u][c])
		return res = getFail(fail[u], c); // u = fail[u];
		
	return res = nex[u][c];
}

void build () {
	queue<int> q;
	
	for (int i = 0; i < 26; i++)
		if (nex[0][i])
			q.push(nex[0][i]);

	while (q.size()) {
		int u = q.front();
		q.pop();

		for (int i = 0; i < SIG; i++) {
			int v = nex[u][i];

			if (v) {
				fail[v] = getFail(fail[u], i);
				cnt[v] += cnt[fail[v]];
				q.push(v);

				/*out[v] = fail[v];
				while (finish[out[v]] == -1)
					out[v] = fail[out[v]];*/
			}
		}
	}
}

int match (string &t) {
	int u = 0, res = 0;

	for (int i = 0; i < t.size(); i++) {
		char c = t[i] - 'a';
		
		if (nex[u][c])
			u = nex[u][c];
		else
			u = getFail(fail[u], c);
		res += cnt[u];

		/*int v = u;
		while (v && cnt[v]) {
			if (finish[v] != -1)
				ocu[finish[v]].push_back(i);
			v = out[v];
		}*/
	}

	return res;
}

string s[MX];
int n, c[MX];

void insert (string &s, int c) {
	set<char> st[256];
	
	forn (i, (int)s.size() - 1) {
		st[s[i]].insert(s[i + 1]);
		st[s[i + 1]].insert(s[i]);
	}
	
	int h = 0, ini;
	forr (i, 'a', 'l') {
		if (st[i].size() > 2) return;
		if (st[i].size() == 1) h++, ini = i;
	}
	
	if (h != 2) return;
	
	string t = {char(ini)};
	
	while (st[ini].size()) {
		int nex = *st[ini].begin();
		t.pb(nex);
		st[ini].erase(nex);
		st[nex].erase(ini);
		ini = nex;
	}
	
	insert(t, 0, c);
	reverse(all(t));
	insert(t, 0, c);
}

int mem[12 * 2005][1 << 12];
int dp (int i, int mk) {
	if (__builtin_popcount(mk) == 12) return 0;
	
	int &res = mem[i][mk];
	if (res != -1) return res;
	res = 0;
	
	forn (c, 12)
		if (~mk & (1 << c)) {
			int nex = getFail(i, c);
			res = max(res, dp(nex, mk | (1 << c)) + cnt[nex]);
		}
	
	return res;
}

void rec (int i, int mk) {
	if (__builtin_popcount(mk) == 12) return;
	
	int &res = mem[i][mk];
	
	forn (c, 12)
		if (~mk & (1 << c)) {
			int nex = getFail(i, c);
			
			if (res == dp(nex, mk | (1 << c)) + cnt[nex]) {
				cout << char('a' + c);
				return rec(nex, mk | (1 << c));
			}
		}
}

void main_() {
	cin >> n;
	forn (i, n) {
		cin >> c[i] >> s[i];
		insert(s[i], c[i]);
	}
	
	memset(memf, -1, sizeof(memf));
	build();
	
	memset(mem, -1, sizeof(mem));
	int res = dp(0, 0);
	rec(0, 0);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}