#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	string s;
	cin >> s;
	
	for (int i = 2; i < s.size(); i++) {
		char a = s[i - 1] - 'A';
		char b = s[i - 2] - 'A';
		char c = (a + b) % 26 + 'A';
		
		if (c != s[i]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	
	cout << "YES" << endl;
	
	return 0;
}