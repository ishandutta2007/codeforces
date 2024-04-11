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

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	string s;

	cin >> n >> s;
	for (int i = 0; i + 1 < n; i++)
		if (s[i] > s[i+1]) {
			cout << "YES" << endl;
			cout << i+1 << " " << i+2 << endl;
			return 0;
		}

	cout << "NO" << endl;
	
	return 0;
}