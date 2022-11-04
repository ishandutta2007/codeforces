#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005, SIG = 26;
int n, nex[MX][SIG], fail[MX], finish[MX], sz = 1, cnt[MX], cn[MX], izq[MX], der[MX];
ll res;
string t, s[MX];

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
			}
		}
	}
}

void match (string &t, int ini[]) {
	int u = 0, res = 0;

	for (int i = 0; i < t.size(); i++) {
		char c = t[i] - 'a';
		
		if (nex[u][c])
			u = nex[u][c];
		else
			u = getFail(fail[u], c);

		ini[i] = cnt[u];
		res += cnt[u];
	}
}

void reset () {
	memset(nex, 0, sizeof(nex));
	memset(fail, 0, sizeof(fail));
	memset(finish, 0, sizeof(finish));
	memset(cnt, 0, sizeof(cnt));
	sz = 1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> t >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		insert(s[i], i);
	}

	build();
	match(t, izq);

	reset();
	for (int i = 1; i <= n; i++) {
		reverse(all(s[i]));
		insert(s[i], i);
	}

	build();
	reverse(all(t));
	match(t, der);

	int i = 0, j = (int)t.size() - 1;
	while (i < j) {
		swap(der[i], der[j]);
		i++, j--;
	}

	for (int i = 0; i < t.size(); i++)
		res += 1ll * izq[i] * der[i + 1];

	cout << res << endl;

	return 0;
}