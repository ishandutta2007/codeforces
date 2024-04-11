
// Problem : A. Charmed by the Game
// Contest : Codeforces - Codeforces Round #740 (Div. 1, based on VK Cup 2021 - Final (Engine))
// URL : https://codeforces.com/contest/1558/problem/A
// Memory Limit : 512 MB
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

int a, b;
set<int> st;

void go (int a, int b, int x, int y) {
	int d = min(a, x);
	int e = min(b, y);
	
	int mn = (a - d) + (b - e);
	
	d = min(a, y);
	e = min(b, x);
	
	int mx = d + e;
	
	for (int i = mn; i <= mx; i += 2)
		st.insert(i);
}

void solve() {
	cin >> a >> b;
	st.clear();
	
	int x = (a + b + 1) / 2;
	int y = (a + b) / 2;
	
	go(a, b, x, y);
	go(a, b, y, x);
	
	cout << st.size() << endl;
	for (int x : st)
		cout << x << " ";
	cout << endl;
} 

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}