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

int n, k;
string s;
vi pos;

void main_() {
	cin >> n >> k >> s;
	pos.clear();
	
	forn (i, n)
		if (s[i] == '1')
			pos.pb(i);
	
	int acu = 11 * pos.size();
	
	if (pos.size() > 1) {
		int x = pos[0];
		int y = n - 1 - pos.back();
		
		if (x + y <= k) {
			cout << acu - 11 << endl;
			return;
		}
	}
	
	if (pos.size() > 0) {
		int y = n - 1 - pos.back();
		
		if (y <= k) {
			cout << acu - 10 << endl;
			return;
		}
	}
	
	if (pos.size() > 0) {
		int x = pos[0];
		
		if (x <= k) {
			cout << acu - 1 << endl;
			return;
		}
	}
	
	cout << acu << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}