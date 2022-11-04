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
typedef double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

typedef list<char> lc;
const int MX = 200005;
lc s;
stack<lc::iterator> st;
int n, sum, cn['z' + 5];
vii res;

void clear (int f = 0) {
	while (st.size()) st.pop();
	if (f) {
		s.clear(), res.clear();
		memset(cn, 0, sizeof(cn));
		sum = 0;
	}
}

bool check () {
	for (int i = 'a'; i <= 'z'; i++)
		if (cn[i] >= (sum + 1) / 2)
			return 0;
	return 1;
}

int erase (lc::iterator jt, int i) {
	auto it = st.top();
	st.pop();
	int x = 0, f = 1;
	cn[*it]--, cn[*jt]--, sum -= 2;

	while (f) {
		f = it != jt;
		auto aux = it;
		aux++;
		s.erase(it);
		x++;
		it = aux;
	}

	res.emplace_back(i - x + 2, i + 1);
	return x;
}

void solve () {
	clear(1);

	string in;
	cin >> in;
	n = in.size();

	forn (i, n - 1) if (in[i] == in[i + 1]) cn[in[i]]++, sum++;

	for (char c : in)
		s.pb(c);

	auto jt = s.begin(), it = jt++;
	for (int i = 0; jt != s.end() && check(); i++, it = jt++)
		if (*it == *jt) {
			if (st.size() && *st.top() != *it) i -= erase(it, i);
			else st.push(jt);
		}

	char ind = 'a';
	for (int i = 'b'; i <= 'z'; i++)
		if (cn[ind] < cn[i])
			ind = i;

	if (s.size()) {
		clear();
		jt = s.begin(), it = jt++;
		for (int i = 0; jt != s.end(); i++, it = jt++)
			if (*it == *jt) {
				if (st.size() && ((*st.top() == ind) ^ (*it == ind))) i -= erase(it, i);
				else st.push(jt);
			}
	}

	if (s.size()) {
 		clear();
		jt = s.begin(), it = jt++;
		for (int i = 0; jt != s.end(); i++, it = jt++)
			if (*it == *jt) {
				if (st.size()) i -= erase(it, i);
				st.push(jt);
			}

		if (st.size())
			erase(--jt, (int)s.size() - 1);
	}

	if (s.size())
		res.emplace_back(1, s.size());

	cout << res.size() << endl;
	for (ii &r : res)
		cout << r.fi << " " << r.se << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}