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

map<string, int> mp;

void main_() {
	string s;
	cin >> s;
	cout << mp[s] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	for (char a = 'a'; a <= 'z'; a++)
		for (char b = 'a'; b <= 'z'; b++)
			if (a != b) {
				int sz = mp.size();
				string s;
				s.pb(a);
				s.pb(b);
				mp[s] = sz + 1;
			}
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}