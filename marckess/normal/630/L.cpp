#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

string s;
int x = 0, w[] = {1, 3, 4, 2, 0};
ll res = 1;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> s;
	
	for (int i = 0, j = 1; i < 5; i++, j *= 10)
		x += (s[w[i]] - '0') * j;

	for (int i = 0; i < 5; i++) {
		res *= x;
		res %= 100000;
	}

	s = to_string(res);
	while (s.size() < 5)
		s = "0" + s;

	cout << s << endl;

	return 0;
}