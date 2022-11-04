
// Problem : G. Robot and Candies
// Contest : Codeforces - Codeforces Round #756 (Div. 3)
// URL : https://codeforces.com/contest/1611/problem/G
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
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

const int MX = 1000005;
int n, m;
set<int> st[MX];
multiset<int> mst[2];

void main_() {
	cin >> n >> m;
	
	forn (i, n)
		forn (j, m) {
			char c;
			cin >> c;
			
			if (c == '1')
				st[i + j].insert(i);
		}
	
	mst[0].clear();
	mst[1].clear();
	
	int res = 0;
	forn (i, n + m) {
		for (int x : st[i]) {
			int y = i - x;
			
			auto it = mst[i % 2].lower_bound(y - x);
			if (it == mst[i % 2].end()) res++;
			else mst[i % 2].erase(it);
			
			mst[i % 2].insert(y - x);
		}
		
		st[i].clear();
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