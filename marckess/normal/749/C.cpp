#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int n;
list<char> l;
char c;
stack<char> st;
int r = 0, d = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c;
		l.push_back(c);
		if (c == 'D')
			d++;
		else
			r++;
	}

	auto it = l.begin();
	while (d && r) {
		if (st.empty() || st.top() == *it) {
			st.push(*it);
			it++;
		} else {
			auto aux = it;
			it++;
			if (*aux == 'D')
				d--;
			else
				r--;
			l.erase(aux);
			st.pop();
		}

		if (it == l.end())
			it = l.begin();
	}

	cout << *l.begin() << endl;

	return 0;
}