#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
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
int n;
string s;

void solve () {
	cin >> n >> s;
	
	int ant = -1;
	forn (i, n) {
		if ((ant == 2 && s[i] == '1') || (ant == 1 && s[i] == '0')) {
			cout << 0;
			ant = s[i] == '1';
		} else {
			cout << 1;
			ant = 1 + (s[i] == '1');
		}
	}
	
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}