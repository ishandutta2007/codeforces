// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
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

const int MX = 100005;
int n;
string s[MX];

bool f () {
	set<string> st;
	
	forn (i, n) {
		if (s[i][0] == s[i].back())
			return 1;
		
		string t = s[i];
		reverse(all(t));
		
		if (st.count(t))
			return 1;
		
		if (t.size() > 1)
			if (st.count(t.substr(0, (int)t.size() - 1)))
				return 1;
		
		st.insert(s[i]);
	}
	
	return 0;
}

void main_() {
	cin >> n;
	forn (i, n)
		cin >> s[i];
	
	if (f()) {
		cout << "YES" << endl;
		return;
	}
	
	reverse(s, s + n);
	forn (i, n)
		reverse(all(s[i]));
	
	if (f()) {
		cout << "YES" << endl;
		return;
	}
	
	cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}