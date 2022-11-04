#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, a[MX];
multiset<int> mst;
map<int, int> mp;

void solve () {
	cin >> n;
	
	mst.clear();
	mp.clear();
	
	forn (i, n) {
		cin >> a[i];
		mst.insert(a[i]);
		mp[a[i]]++;
	}
	
	int x = *mst.begin();
	for (auto it : mp)
		if (mp[x] < it.se)
			x = it.fi;
	
	if (mp[x] >= 2) {
		mst.erase(mst.find(x));
		mst.erase(mst.find(x));
		
		cout << x << " ";
		
		int y = x;
		while (mst.size()) {
			auto it = mst.lower_bound(y);
			
			if (it == mst.end()) {
				y = 0;
				continue;
			}
			
			y = *it;
			cout << y << " ";
			mst.erase(it);
		}
		
		cout << x << endl;
	} else {
		sort(a, a + n);
		
		int ind = 1;
		for (int i = 1; i < n; i++)
			if (a[i] - a[i - 1] < a[ind] - a[ind - 1])
				ind = i;
			
			swap(a[ind], a[ind - 1]);
			for (int i = ind; i < n; i++)
				cout << a[i] << " ";
			for (int i = 0; i < ind; i++)
				cout << a[i] << " ";
			cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}