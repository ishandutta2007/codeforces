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
const int N = 1e5 + 10;
int n, q;
int a[N], cnt = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	rep(i, 1, n) cin >> a[i], cnt += a[i];
	rep(i, 1, q) {
		int t, x;
		cin >> t >> x;
		if(t == 1) {
			cnt -= a[x];
			a[x] ^= 1;
			cnt += a[x];
		} else {
			if(x <= cnt) cout << "1\n";
			else cout << "0\n";
		}
	}
	
	return 0;
}