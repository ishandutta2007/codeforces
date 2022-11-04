#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
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

const int MX = 5000;

int x;
vector<string> vs;

void pre (int sum, string &s) {
	if (sum < 0) return;

	if (sum == 0) {
		bool prime = 1;

		forn (i, s.size()) {
			int t = 0;

			for (int j = i; j < s.size(); j++) {
				t += s[j] - '0';

				if (t < x && x % t == 0) 
					prime = 0;
			}
		}

		if (prime)
			vs.pb(s);

		return;
	}

	for (int i = '1'; i <= '9'; i++) {
		s.pb(i);
		pre(sum - (i - '0'), s);
		s.pop_back();
	}
}

int nex[MX][10], fail[MX], go[MX][10], fin[MX], sz;

void insert (string &s) {
	int u = 0;

	for (char c : s) {
		c -= '0';
		if (!nex[u][c])
			nex[u][c] = ++sz;
		u = nex[u][c];
	}

	fin[u] = 1;
}

void build () {
	queue<int> q;

	for (int c = 0; c < 10; c++)
		if (nex[0][c]) {
			q.push(nex[0][c]);
			go[0][c] = nex[0][c];
		}

	while (q.size()) {
		int u = q.front();
		q.pop();

		fin[u] |= fin[fail[u]];

		for (int c = 0; c < 10; c++) {
			if (nex[u][c]) {
				q.push(nex[u][c]);
				fail[nex[u][c]] = go[fail[u]][c];
				go[u][c] = nex[u][c];
			} else {
				go[u][c] = go[fail[u]][c];
			}
		}
	}
}

int mem[1005][MX];
string s;

int dp (int i, int j) {
	if (fin[j]) return 1e9;
	if (i == s.size()) return 0;

	int &res = mem[i][j];
	if (res != -1) return res;
	
	return res = min(
		dp(i + 1, j) + 1,
		dp(i + 1, go[j][s[i] - '0'])
	);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> s >> x;

	string kk;
	pre(x, kk);
	
	for (auto s : vs)
		insert(s);
	build();

	memset(mem, -1, sizeof(mem));
	cout << dp(0, 0) << endl;

	return 0;
}