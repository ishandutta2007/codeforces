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
typedef vector<ii> vii;

string s;
ll res = 1;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);	

	cin >> s;

	for (char a = 'a'; a <= 'z'; a++)
		for (int b = 'a'; b <= 'z'; b++) {
			ll cn = 0;
			ll acu = 0;
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == b) acu += cn;
				if (s[i] == a) cn++;
			}
			res = max({res, cn, acu});
		}

	cout << res << endl;

	return 0;
}