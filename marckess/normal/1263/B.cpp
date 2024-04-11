#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int n;
string s[10];

bool valid (int i) {
	for (int j = 0; j < n; j++)
		if (i != j && s[i] == s[j])
			return 0;
	return 1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> s[i];
		
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (valid(i))
				continue;
			res++;
			for (int j = '0'; j <= '9'; j++) {
				s[i][0] = j;
				if (valid(i))
					break;
			}
		}

		cout << res << endl;
		for (int i = 0; i < n; i++)
			cout << s[i] << endl;
	}

	return 0;
}