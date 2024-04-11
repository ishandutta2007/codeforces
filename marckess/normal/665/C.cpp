#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> s;
	s.pb('0');

	for (int i = 1; i + 1 < s.size(); i++)
		if (s[i] == s[i - 1]) {
			if (s[i - 1] != 'a' && s[i + 1] != 'a') s[i] = 'a';
			if (s[i - 1] != 'b' && s[i + 1] != 'b') s[i] = 'b';
			if (s[i - 1] != 'c' && s[i + 1] != 'c') s[i] = 'c';
		}

	s.pop_back();
	cout << s << endl;

	return 0;
}