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

const int MX = 100005;
int n, m, k, a[MX];

void main_() {
	cin >> n >> m >> k;
	forn (i, k)
		cin >> a[i];
	
	set<int> st;
	int j = k;
	
	forn (i, k) {
		if (st.size() == n * m - 3) {
			cout << "TIDAK" << endl;
			return;
		}
		
		st.insert(a[i]);
		while (st.count(j))
			st.erase(j--);
	}
	
	assert(st.empty());
	cout << "YA" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}