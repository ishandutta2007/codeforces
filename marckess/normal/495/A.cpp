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

int d[] = {
	1,
	6,
	1,
	2,
	2,
	3,
	1,
	4,
	0,
	1
};

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	string s;
	cin >> s;
	cout << (d[s[0] - '0'] + 1) * (d[s[1] - '0'] + 1) << endl;

	return 0;
}