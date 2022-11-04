#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> s >> s;
	bitset<27> bs;

	for (char c : s) {
		if ('a' <= c && c <= 'z')
			bs[c-'a'] = 1;
		else
			bs[c-'A'] = 1;
	}

	if (bs.count() == 26)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}