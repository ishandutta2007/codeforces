#include<bits/stdc++.h>

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define x first
#define y second
#define mp make_pair
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef pair<int, int> par;
typedef long long LL;
typedef double db;
int q;


void solve(int u, int v) {
	if(u > v) return cout << "NO\n", void();
	int cu = 0, cv = 0;
	rep(i, 0, 29) {
		if((u >> i) & 1) cu++;
		if((v >> i) & 1) cv++;
	}
	if(cu < cv) return cout << "NO\n", void();
	cu = cv = 0;
	rep(i, 0, 29) {
		if((u >> i) & 1) cu++;
		if((v >> i) & 1) {
			if(cu) cu--;
			else return cout << "NO\n", void();
		}
	}
	cout << "YES\n";
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> q;
	while(q--) {
		int u, v;
		cin >> u >> v;
		solve(u, v);
	}
	return 0;
}