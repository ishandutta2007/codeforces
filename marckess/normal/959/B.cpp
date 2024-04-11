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

struct trie {
	map<char, trie*> mp;
	int ind;

	void insert (int i, int j, string &s) {
		if (i == s.size()) {
			ind = j;
			return;
		}

		if (mp.find(s[i]) == mp.end())
			mp[s[i]] = new trie();

		mp[s[i]]->insert(i+1, j, s);
	}

	int find (int i, string &s) {
		return i == s.size() ? ind : mp[s[i]]->find(i+1, s);
	}
};

int n, k, m, a[100005], g[100005], mn[100005], x, y;
string s;
trie* t = new trie();

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    fill (mn, mn+100005, 1e9);

    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++) {
    	cin >> s;
    	t->insert(0, i, s);
    }

 	for (int i = 1; i <= n; i++)
 		cin >> a[i];

 	for (int i = 1; i <= k; i++) {
 		cin >> x;
 		while (x--) {
 			cin >> y;
 			g[y] = i;
 			mn[i] = min(a[y], mn[i]);
 		}
 	}

 	ll res = 0;
 	while (m--) {
 		cin >> s;
 		res += mn[g[t->find(0, s)]];
 	}
 	cout << res << endl;

    return 0;
}