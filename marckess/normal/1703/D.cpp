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

const int MX = 100005;
int n;
string s[MX];
set<string> st;

void main_() {
	cin >> n;
	st.clear();
	
	forn (i, n) {
		cin >> s[i];
		st.insert(s[i]);
	}
	
	forn (i, n) {
		int f = 0;
		forr (j, 1, (int)s[i].size() - 1) {
			string a = s[i].substr(0, j);
			string b = s[i].substr(j);
			
			f |= st.count(a) && st.count(b);
		}
		cout << f;
	}
	
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