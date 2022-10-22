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
int n, u, v;
int a[N];
int work() {
	cin >> n >> u >> v;
	rep(i, 1, n) cin >> a[i];
	rep(i, 2, n) if(abs(a[i] - a[i - 1]) >= 2) return 0;
	rep(i, 2, n) if(abs(a[i] - a[i - 1]) >= 1) return min(u, v);
	return min(u + v, v * 2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for(; T--; ) cout << work() << endl;
	return 0;
}