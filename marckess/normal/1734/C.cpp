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

const int MX = 1000005;
int n, si[MX], no[MX];
string s;

void main_() {
	cin >> n >> s;
	s = " " + s;
	
	forr (i, 1, n) {
		if (s[i] == '0') si[i] = 0, no[i] = 1;
		else si[i] = 1, no[i] = 0;
	}
	
	ll res = 0;
	forr (i, 1, n) {
		for (int j = i; j <= n; j += i) {
			if (si[j]) break;
			if (no[j]) {
				res += i;
				no[j] = 0;
			}
		}
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