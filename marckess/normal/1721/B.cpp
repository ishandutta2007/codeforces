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

int n, m, sx, sy, d;

void main_() {
	cin >> n >> m >> sx >> sy >> d;
	
	#define no { cout << -1 << endl; return; }
	
	if (sx - d <= 1 && sy - d <= 1) no;
	if (sx + d >= n && sy + d >= m) no;
	if (sx - d <= 1 && sx + d >= n) no;
	if (sy - d <= 1 && sy + d >= m) no;
	
	cout << n + m - 2 << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}