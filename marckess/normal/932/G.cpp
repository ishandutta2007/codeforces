#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1e6+5, SIG = 26;
int str[MX], len[MX], link[MX], to[MX][SIG], slink[MX], dif[MX];
int cur, sl, sz;

void init () {
	memset(to, 0, sizeof(to));
	cur = sl = 0;
	str[sl++] = -1;

	link[0] = 1, len[0] = 0;
	link[1] = 0, len[1] = -1;

	sz = 2;
}

int getLink (int v) {
	while (str[sl - len[v] - 2] != str[sl - 1]) v = link[v];
	return v;
}

void insert (int c) {
	str[sl++] = c;
	cur = getLink(cur);

	if (!to[cur][c]) {
		len[sz] = len[cur] + 2;
		link[sz] = to[getLink(link[cur])][c];
		dif[sz] = len[sz] - len[link[sz]];

		if (dif[sz] == dif[link[sz]]) slink[sz] = slink[link[sz]];
		else slink[sz] = link[sz];

		to[cur][c] = sz++;
	}

	cur = to[cur][c];
}

const int mod = 1e9+7;
string s, in;
int dp[MX], acu[MX];

void sum (int &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> in;
	for (int i = 0; s.size() < in.size(); i++)
		s.pb(in[i]), s.pb(in[in.size() - i - 1]);

	init();

	dp[0] = 1;

	for (int i = 1; i <= s.size(); i++) {
		insert(s[i-1]-'a');
		
		for (int j = cur; j > 1; j = slink[j]) {
			acu[j] = dp[i - len[slink[j]] - dif[j]];
			if (dif[j] == dif[link[j]])
				sum(acu[j], acu[link[j]]);
			sum(dp[i], acu[j]);
		}

		if (i % 2) dp[i] = 0;
	}

	cout << dp[s.size()] << endl;

	return 0;
}