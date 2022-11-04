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

const int MX = 200005;
int n, k, to[256], mp[256];
string s;

void main_() {
	cin >> n >> k >> s;
	
	for (int i = 'a'; i <= 'z'; i++) {
		to[i] = 0;
		mp[i] = i;
	}
	
	for (char c : s) {
		while (mp[c] != 'a') {
			if (k || to[mp[c]]) {
				k -= !to[mp[c]];
				to[mp[c]] = 1;
				mp[c]--;
			} else {
				break;
			}
		}
	}
	
	for (char c : s)
		cout << char(mp[c]);
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