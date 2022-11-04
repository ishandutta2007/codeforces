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

int q, d, k;
char ma, mb;
ll sa, sb;

void main_() {
	cin >> q;
	
	ma = 'a';
	mb = 'a';
	sa = 1;
	sb = 1;
	
	while (q--) {
		int d, k;
		string s;
		cin >> d >> k >> s;
		
		char m = 'a';
		for (char c : s)
			m = max(m, c);
		
		if (d == 1) {
			ma = max(ma, m);
			sa += ll(s.size()) * k;
		} else {
			mb = max(mb, m);
			sb += ll(s.size()) * k;
		}
		
		if (mb > 'a') cout << "YES" << endl;
		else if (ma > 'a') cout << "NO" << endl;
		else if (sa < sb) cout << "YES" << endl;
		else cout << "NO" << endl; 
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}