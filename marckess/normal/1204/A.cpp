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
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> s;
	int res = s.size() / 2;
	if (s == "0") {
		cout << 0 << endl;
		return 0;
	}

	s.erase(s.begin());
	if (s.size() % 2 == 0 && s.find('1') != string::npos) res++;
	cout << res << endl;

	return 0;
}