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

vi pos[256], res;

void main_() {
	int n;
	string s;
	
	cin >> s;
	n = s.size();
	
	forr (i, 'a', 'z')
		pos[i].clear();
	res.clear();
	
	forn (i, n)
		pos[s[i]].pb(i);
	
	if (s[0] < s.back()) {
		cout << s.back() - s[0] << " ";
		forr (i, s[0], s.back())
			for (int j : pos[i])
				res.pb(j);	
	} else {
		cout << s[0] - s.back() << " ";
		for (int i = s[0]; i >= s.back(); i--)
			for (int j : pos[i])
				res.pb(j);
	}
	cout << res.size() << endl;
	for (int i : res)
		cout << i + 1 << " ";
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