#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int a;
ll res;
string s;
map<int, int> mp;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> a >> s;

	forn (i, s.size()) {
		int x = 0;
		for (int j = i; j < s.size(); j++) {
			x += s[j] - '0';
			if (x && a && a % x == 0) mp[x]++;
			if (!x && !a) mp[x]++;
		}
	}


	forn (i, s.size()) {
		int x = 0;
		for (int j = i; j < s.size(); j++) {
			x += s[j] - '0';
			if (x && a && a % x == 0) res += mp[a / x];
			if (!x && !a) res += s.size() * (s.size() + 1) / 2;
			else if (!a) res += mp[0];
		}
	}

	cout << res << endl;

	return 0;
}