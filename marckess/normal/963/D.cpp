#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 100010, SIG = 26;

//-----------------Aho Corasick---------------//
int nex[MX][SIG], fail[MX], out[MX], finish[MX], cnt[MX], sz = 1;
vi ocu[MX];

void insert (string &s, int ind) {
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
}

int getFail (int u, int c) {
	while (u && !nex[u][c])
		u = fail[u];
	return nex[u][c];
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
				while (finish[out[v]] == -1)
					out[v] = fail[out[v]];
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

		int v = u;
		while (v) {
			if (finish[v] != -1)
				ocu[finish[v]].push_back(i);
			v = out[v];
		}
	}

	return res;
}
//----------------------------------------------//

string t, s[MX];
int n, m[MX];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> t >> n;
    for (int i = 0; i < n; i++) {
    	cin >> m[i] >> s[i];
    	insert(s[i], i);
    }

    build();
    match(t);

    for (int i = 0; i < n; i++) {
    	if (ocu[i].size() < m[i]) {
    		cout << -1 << endl;
    	} else {
    		int res = 1e9;
    		for (int k = m[i] - 1; k < ocu[i].size(); k++)
    			res = min(res, ocu[i][k] - ocu[i][k-m[i]+1] + int(s[i].size()));
    		cout << res << endl;
    	}
    }

    return 0;
}