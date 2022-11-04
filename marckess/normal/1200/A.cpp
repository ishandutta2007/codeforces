#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int n, res[10];
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> s;
	for (int c : s) {
		if (c == 'L') {
			for (int j = 0; j < 10; j++)
				if (!res[j]) {
					res[j] = 1;
					break;
				}
		} else if (c == 'R') {
			for (int j = 9; j + 1; j--)
				if (!res[j]) {
					res[j] = 1;
					break;
				}
		} else {
			res[c-'0'] = 0;
		}
	}

	for (int i = 0; i < 10; i++)
		cout << res[i];
	cout << endl;
 
	return 0;
}