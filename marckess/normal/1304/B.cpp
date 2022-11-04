#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MX = 105;
int n, m;
string s[MX], a;
multiset<string> st;
stack<string> b;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		string t = s[i];
		reverse(all(t));

		if (st.count(t)) {
			a += t;
			b.push(s[i]);
			st.erase(st.find(t));
		} else {
			st.insert(s[i]);
		}
	}

	for (string s : st) {
		string t = s;
		reverse(all(t));
		if (t == s) {
			a += s;
			break;
		}
	}

	while (b.size()) {
		a += b.top();
		b.pop();
	}

	cout << a.size() << endl;
	cout << a << endl;

	return 0;
}