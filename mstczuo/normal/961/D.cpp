# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define all(a) a.begin(),a.end()
#define For(i, l, r) for(int i = l; i <= r; ++i)
#define rep(i, n) For(i, 0, n-1)
#define pb push_back

const int N = 100010;
void rd(int &x) { scanf("%d", &x); }
int x[N], y[N], n;

bool vis[N];

ll cross(int x1,int y1,int x2,int y2) {
	return 1ll * x1 * y2 - 1ll * y1 * x2;
}

void line(int x0,int y0,int x1,int y1) {
	rep(i, n) if(cross(x1 - x0, y1 - y0, x[i] - x0, y[i] - y0) == 0) vis[i] = true;
}

bool cal(int i,int j) {
	vector<int> vi;
	memset(vis, 0, sizeof vis);
	line(x[i], y[i], x[j], y[j]);
	rep(k, n) if(!vis[k]) vi.pb(k);
	if(vi.size() <= 2) return true;
	i = vi[0];
	j = vi[1];
	line(x[i], y[i], x[j], y[j]);
	rep(k, n) if(!vis[k]) return false;
	return true;
}

int main() {
	rd(n);
	rep(i, n) rd(x[i]), rd(y[i]);
	if (n <= 4 || cal(0, 1) || cal(0, 2) || cal(1, 2)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}