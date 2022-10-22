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
const int N = 1e5 + 10;
int n;
vector<int> g[N];
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		g[x].push_back(i);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(g[i].empty()) continue;
		vector<int> l, r;
		int pr = -1, sf = -1;
		for(int j = 0; j < (int)g[i].size(); j++) {
			if(sf + 1 == g[i][j]) {
				sf = g[i][j];
			} else {
				if(pr != -1) l.push_back(pr), r.push_back(sf);
				pr = g[i][j], sf = g[i][j];
			}
		}
		l.push_back(pr), r.push_back(sf);
		for(int j = 0; j < (int)l.size(); j++) {
			if(r[j] - l[j] + 1 >= 2) ans += 2;
			else ans++;
		}
		int bh = 0;
		for(int j = 0; j < (int)l.size(); j++) {
			if(j > 0) bh -= l[j] - r[j - 1] - 1;
			bh = max(bh, 0);
			int t = r[j] - l[j] + 1;
			if(t > 2) t = 2;
			if(2 - bh < t) ans -= t - (2 - bh);
			bh += t;
			bh = min(bh, 2);
		}
	}
	printf("%d\n", ans);
	return 0;
}