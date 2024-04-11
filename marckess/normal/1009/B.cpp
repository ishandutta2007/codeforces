#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

char c;
int cn = 0;
list<char> l;

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	while (cin >> c)
		l.push_back(c);

	for (auto it = l.begin(); it != l.end();) {
		if (*it == '1') {
			auto aux = it;
			it++;
			l.erase(aux);
			cn++;
		} else {
			it++;
		}
	}

	auto it = l.begin();
	while (1) {
		if (it == l.end() || *it == '2') {
			while (cn) {
				l.insert(it, '1');
				cn--;
			}
			break;
		}
		it++;
	}

	for (char c : l)
		cout << c;
	cout << endl;

	return 0;
}