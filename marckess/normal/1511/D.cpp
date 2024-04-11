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

int n, k, vis[256];
string s, t[30];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	
	for (int i = 1; i < k; i++) {
		t[i].pb('a' + i);
		for (int j = i + 1; j < k; j++) {
			t[i].pb('a' + j);
			t[i].pb('a' + i);
		}
	}
	
	s = "aa";
	for (int i = 1; i < k; i++)
		s += char('a' + i) + t[i] + "a";
	s.pop_back();
	
	forn (i, n)
		cout << s[i % int(s.size())];
	cout << endl;
	
	return 0;
}