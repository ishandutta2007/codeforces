
// Problem : E. Crazy Robot
// Contest : Codeforces - Educational Codeforces Round 118 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1613/problem/E
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

const int MX = 1000005;
int n, m;
int mx[] = {1, -1, 0, 0};
int my[] = {0, 0, 1, -1};
vector<string> c;

bool valid (int i, int j) {
	if (i < 0 || n <= i) return 0;
	if (j < 0 || m <= j) return 0;
	if (c[i][j] != '.') return 0;
	
	int cn = 0;
	forn (l, 4) {
		int x = i + mx[l];
		int y = j + my[l];
		
		if (x < 0 || n <= x) continue;
		if (y < 0 || m <= y) continue;
		cn += c[x][y] == '.';
	}
	
	return cn <= 1;
}

void main_() {
	cin >> n >> m;
	c.resize(n);
	
	forn (i, n)
		cin >> c[i];
	
	queue<ii> q; 
	forn (i, n)
		forn (j, m)
			if (c[i][j] == 'L')
				q.emplace(i, j);
	
	while (q.size()) {
		auto [i, j] = q.front();
		q.pop();
		
		forn (l, 4) {
			int x = i + mx[l];
			int y = j + my[l];
			if (valid(x, y)) {
				c[x][y] = '+';
				q.emplace(x, y);
			}
		}
	}
	
	forn (i, n)
		cout << c[i] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}