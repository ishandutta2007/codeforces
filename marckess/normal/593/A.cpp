#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int n;
map<int, int> mp;
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	while (n--) {
		cin >> s;

		int mk = 0, cn = 0;
		for (char c : s) {
			c -= 'a';
			mk |= (1 << c);
		}
		
		mp[mk] += s.size();
	}

	int res = 0;
	for (int i = 0; i <= 'z' - 'a'; i++)
		for (int j = 0; j <= 'z' - 'a'; j++)
			if (i != j)
				res = max(res, mp[1<<i] + mp[1<<j] + mp[(1<<i)|(1<<j)]);

	cout << res << endl;

	return 0;
}