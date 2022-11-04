// Powered by CP Editor (https://cpeditor.org)

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

string s;
int p;
list<char> l;
vector<list<char>::iterator> pos[256];

void main_() {
	cin >> s >> p;
	int tot = 0;
	
	forr (i, 'a', 'z')
		pos[i].clear();
	l.clear();
	
	for (char c : s) {
		tot += c - 'a' + 1;
		pos[c].pb(l.insert(l.end(), c));
	}
	
	for (int c = 'z'; c >= 'a'; c--)
		for (auto it : pos[c])
			if (tot > p) {
				tot -= c - 'a' + 1;
				l.erase(it);
			}
	
	for (auto c : l)
		cout << c;
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}