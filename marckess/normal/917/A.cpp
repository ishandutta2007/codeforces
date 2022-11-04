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

int res, n;
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> s;
	n = s.size();

	forn (i, n) {
		int st = 0, x = 0;
		for (int j = i; j < n; j++) {
			if (s[j] == ')') st--;
			else if (s[j] == '(') st++;
			else st--, x++;

			if (st < 0) {
				if (x) st += 2, x--;
				else break;
			}

			if (st == 0) res++;
		} 
	}

	cout << res << endl;

	return 0;
}