#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n, q;
multiset<int> mst[33];
ll s[33];

int find (int x) {
	int res = 0;
	forn (i, 30)
		if (x & (1 << i))
			res = i;
	return res;
}

void main_() {
	cin >> q;
	
	forn (kk, q) {
		char op;
		int x;
		cin >> op >> x;
		
		int k = find(x);
		
		if (op == '+') {
			s[k] += x;
			mst[k].insert(x);
			n++;
		} else {
			s[k] -= x;
			mst[k].erase(mst[k].find(x));
			n--;
		}
		
		ll tot = 0;
		int res = n;
		
		forn (i, 30) {
			if (mst[i].size())
				if (2 * tot < *mst[i].begin())
					res--;
			tot += s[i];
		}
		
		cout << res << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}