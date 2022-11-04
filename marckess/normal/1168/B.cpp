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
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

string s;
int sig;
ll res = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> s;

	sig = s.size();
	for (int i = (int)s.size() - 1; i >= 0; i--) {
		for (int k = 1; i + 2 * k < sig; k++)
			if (s[i] == s[i+k] && s[i] == s[i+2*k]) {
				sig = i + 2 * k;
				break;
			}
		res += s.size() - sig;
	}

	cout << res << endl;

	return 0;
}