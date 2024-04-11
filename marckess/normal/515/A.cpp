#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int a, b, s;

	cin >> a >> b >> s;
	s -= abs(a) + abs(b);

	if (s >= 0 && s % 2 == 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}