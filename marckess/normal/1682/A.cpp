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

const int MX = 100005;
string s;
map<ii, int> mp;
int n;

int dp (int i, int j) {
	if (i >= j) return 1;
	
	if (mp.count({i, j})) return mp[{i, j}];
	return mp[{i, j}] = (s[i] == s[j]) && dp(i + 1, j - 1);
}

void main_() {
	cin >> n >> s;
	mp.clear();
	
	int i = 0, j = n - 1, res = 0;
	mp.clear();
	while (i < j) {
		res += dp(i, j - 1);
		res += dp(i + 1, j);
		
		if (s[i] != s[j])
			break;
		i++, j--;
	}
	
	if (i == j)
		res++;
	
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