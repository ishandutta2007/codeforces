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

const int MX = 2005;
int n, k;
string s, res;

void main_() {
	cin >> n >> k >> s;
	
	map<char, int> mp;
	for (char c : s)
		mp[c]++;
	
	res = string(k, 'a');
	int mn = k;
	
	forr (i, 'a', min((int)'y', (int)'a' + n / k - 1)) {
		mn = min(mn, mp[i]);
		forn (j, mn)
			res[j]++;
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}