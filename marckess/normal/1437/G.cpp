#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300010, SIG = 26;
int nex[MX][SIG], fail[MX], out[MX], finish[MX], cnt[MX], mx[MX], sz = 1;
int go[MX][SIG];

int insert (string &s, int ind) {
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
	cnt[u]++;
	return u;
}

int getFail (int u, int c) {
	if (!u || nex[u][c]) return nex[u][c];
	int &res = go[u][c];
	if (res != -1) return res;
	return res = getFail(fail[u], c);
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

				out[v] = fail[v];
				if (finish[out[v]] == -1)
					out[v] = fail[out[v]];
			}
		}
	}
}

int match (string &t) {
	int u = 0, res = -1;

	for (int i = 0; i < t.size(); i++) {
		char c = t[i] - 'a';
		
		if (nex[u][c])
			u = nex[u][c];
		else
			u = getFail(fail[u], c);

		int v = u;
		while (v && cnt[v]) {
			if (finish[v] != -1)
				res = max(res, mx[v]);
			v = out[v];
		}
	}

	return res;
}

int n, q, in[MX], w[MX];
string s[MX];
multiset<int> mst[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(go, -1, sizeof(go));
	
	cin >> n >> q;
	forn (i, n) {
		cin >> s[i];
		in[i] = insert(s[i], i);
		mst[in[i]].insert(0);
	}
	
	build();
	
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int i, x;
			cin >> i >> x;
			i--;
			
			int u = in[i];
			mst[u].erase(mst[u].find(w[i]));
			mst[u].insert(x);
			w[i] = x;
			
			mx[u] = *mst[u].rbegin();
		} else {
			string s;
			cin >> s;
			cout << match(s) << endl;
		}
	}
	
	return 0;
}