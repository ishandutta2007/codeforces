#include <bits/stdc++.h>

//#define endl '\n'
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

int n;
multiset<string> st[105];
string res;

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	cout << "? 1 " << n << endl;
	forn (i, n * (n + 1) / 2) {
		string s;
		cin >> s;
		sort(all(s));
		st[s.size()].insert(s);
	}

	if (n > 1) {
		cout << "? 1 " << n - 1 << endl;
		forn (i, n * (n - 1) / 2) {
			string s;
			cin >> s;
			sort(all(s));
			st[s.size()].erase(st[s.size()].find(s));
		}
	}	

	for (int i = n; i >= 1; i--) {
		multiset<char> ms;

		for (auto c : *st[i].begin())
			ms.insert(c);
		
		for (auto c : *st[i - 1].begin())
			ms.erase(ms.find(c));

		res.pb(*ms.begin());
	}

	cout << "! " << res << endl;

	return 0;
}