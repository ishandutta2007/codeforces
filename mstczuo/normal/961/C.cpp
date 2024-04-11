# include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define all(a) a.begin(),a.end()
#define For(i, l, r) for(int i = l; i <= r; ++i)
#define rep(i, n) For(i, 0, n-1)
#define pb push_back

void rd(int &x) { scanf("%d", &x); }

char a[120][120];

int c0[4], c1[4];
int main() {
	int n;
	rd(n);
	rep(k, 4) {
		rep(i, n) scanf("%s", a[i]);
		rep(i, n) rep(j, n) 
			c0[k] += (a[i][j] - '0') == ((i + j) & 1);
		c1[k] = n * n - c0[k];
	}
	int ans = n * n * 4;
	rep(i, 16) if(__builtin_popcount(i)==2) {
		int cost = 0;
		rep(k, 4) cost += (i>>k&1) ? c1[k] : c0[k];
		ans = min(ans, cost);
	}
	cout << ans << endl;
	return 0;
}