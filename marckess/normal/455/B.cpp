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

	void insert (int i, string &s) {
		if (i == s.size())
			return;

		if (mp.find(s[i]) == mp.end())
			mp[s[i]] = new trie();
		mp[s[i]]->insert(i+1, s);
	}

	int obtRes () {
		if (mp.empty())
			return 2;

		int d = 0;

		for (auto it : mp) {
			int e = it.se->obtRes();

			if (!(e & 2))
				d |= 2;
			if (!(e & 1))
				d |= 1;
		}

		return d;
	}
};

int n, k;
string s;
trie *t = new trie();

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> k;
    while (n--) {
    	cin >> s;
    	t->insert(0, s);
    }

    int d = t->obtRes(), g = (d & 1), p = (d & 2);

    if (!g)
    	cout << "Second" << endl;
    else if (g && p)
    	cout << "First" << endl;
    else if (k % 2)
    	cout << "First" << endl;
    else
    	cout << "Second" << endl;

    return 0;
}