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

const int MX = 200005;
int n;
multiset<int> a, b;

void main_() {
	cin >> n;
	
	a.clear();
	b.clear();
	
	forn (i, n) {
		int x;
		cin >> x;
		a.insert(x);
	}
	forn (i, n) {
		int x;
		cin >> x;
		b.insert(x);
	}
	
	int res = 0;
	
	while (a.size() && b.size()) {
		int x = *a.rbegin();
		a.erase(a.find(x));
		
		int y = *b.rbegin();
		b.erase(b.find(y));
		
		if (x == y) continue;
		
		if (x > y) {
			x = to_string(x).size();
		} else {
			y = to_string(y).size();
		}
		
		a.insert(x);
		b.insert(y);
		res++;
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}