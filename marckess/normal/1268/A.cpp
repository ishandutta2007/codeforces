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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int n, k;
string s, res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k >> s;
	
	int f = 1;
	for (int i = 0; i < n; i++)
		if (s[i] != s[i % k]) {
			f &= s[i] < s[i % k];
			break;
		}
	
	cout << n << endl;
	if (!f) {
		for (int i = k - 1; i >= 0; i--)
			if (s[i] < '9') {
				s[i]++;
				for (int j = i + 1; j < k; j++)
					s[j] = '0';
				break;
			}
	}

	for (int i = 0; i < n; i++)
			cout << s[i % k];
		cout << endl;

	return 0;
}