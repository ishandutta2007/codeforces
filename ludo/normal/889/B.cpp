#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int maxn = 1e5;

int nxt[26] = {};
bool used[26] = {}, vis[26] = {}, inmid[26] = {};

bool run()
{
	fill_n(nxt, 26, -1);

	int N;
	cin >> N;
	REP(i, N) {
		string str;
		cin >> str;

		vector<bool> seen(26, false);
		for (char ch : str) { 
			used[ch - 'a'] = true;
			if (seen[ch - 'a']) return false;
			seen[ch - 'a'] = true;
		}
		

		int len = str.size();
		for (int j = 1; j < len; j++) {
			int x0 = str[j-1] - 'a';
			int x1 = str[j] - 'a';
			if (nxt[x0] < 0) nxt[x0] = x1, inmid[x1] = true;
			if (nxt[x0] != x1) return false;
		}
	}

	vi ans;
	for (int i = 0; i < 26; i++) {
		if (!used[i] || vis[i] || inmid[i]) continue;

		for (int j = i; j >= 0; j = nxt[j]) {
			if (vis[j]) return false;
			vis[j] = true;
			ans.pb(j);
		}
	}
	if (ans.empty()) return false;
	for (int i = 0; i < 26; i++) {
		if (used[i] && !vis[i]) return false;
	}

	for (int i : ans) cout << ((char) (i + 'a'));
	cout << endl;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (!run()) {
		cout << "NO" << endl;
	}
	return 0;
}