#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S | (1 << j ) )
#define LSB(S) (S & (-S))

int n;
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	int res = 0, con;
	while (cin >> s) {
		con = 0;
		for (char c : s)
			if (c >= 'A' && c <= 'Z')
				con++;
		res = max(res, con);
	}

	cout << res << endl;

	return 0;
}