// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

// #define endl '\n'
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

int n;
string s;

int query (int l, int r) {
	cout << "? 2 " << l + 1 << " " << r + 1 << endl;
	int res;
	cin >> res;
	return res;
}

char query (int i) {
	cout << "? 1 " << i + 1 << endl;
	char res;
	cin >> res;
	return res;
}

void main_() {
	cin >> n;
	s = string(n, ' ');
	
	forn (i, n) {
		vi last, vis(256);
		
		for (int j = i - 1; j >= 0; j--)
			if (!vis[s[j]]) {
				vis[s[j]] = 1;
				last.pb(j);
			}
		sort(all(last));
		
		int l = 0, r = (int)last.size() - 1;
		while (l < r) {
			int m = (l + r + 1) / 2;
			if (query(last[m], i) == (int)last.size() - m) {
				l = m;
			} else {
				r = m - 1;
			}
		}
		
		if (last.size() && query(last[l], i) == (int)last.size() - l) {
			s[i] = s[last[l]];
		} else {
			s[i] = query(i);
		}
	}
	
	cout << "! " << s << endl;
}

int main() {
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}