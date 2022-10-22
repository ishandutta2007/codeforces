#include<bits/stdc++.h>

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define forgp(u, g, v) for(int iu = 0, v; iu < (int)g[u].size() && (v = g[u][iu], 1); iu++)
#define mp make_pair
#define siz(v) (int)(v).size()
#define x first
#define y second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef double db;
const int inf = 0x3f3f3f3f, N = 1e5 + 10;
int n;
int a[N];
int ask(int x) {
	if(x <= 0 || x > n) return inf;
	cout << "? " << x << endl;
	cin >> x;
	return x;
}

int main() {
	scanf("%d", &n);
	int l = 0, r = n;
	while(l + 1 < r) {
		int mid = (l + r) / 2;
		if(ask(mid) > ask(mid + 1)) l = mid;
		else r = mid;
	}
	cout << "! " << r << endl;
	return 0;
}