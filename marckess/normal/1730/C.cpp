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

int n;
string s;
vi pos[256];

void main_() {
	cin >> s;
	n = s.size();
	
	forr (i, '0', '9')
		pos[i].clear();
	
	forn (i, n)
		pos[s[i]].pb(i);
	
	int i = 0;
	while (i < n) {
		forr (c, '0', '9') {
			auto it = lower_bound(all(pos[c]), i);
			if (it == pos[c].end())
				continue;
			
			int j = *it;
			forr (k, i, j - 1)
				s[k] = min(char(s[k] + 1), '9');
			
			i = j + 1;
			break;
		}
	}
	
	sort(all(s));
	cout << s << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}