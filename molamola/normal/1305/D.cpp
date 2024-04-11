#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

int n;
vector <int> E[1010];

int ask(int x, int y) {
	printf("? %d %d\n", x, y);
	fflush(stdout);
	int r; scanf("%d", &r);
	if(r == -1) exit(0);
	return r;
}

void output(int v) {
	printf("! %d\n", v);
}

int dfs(int x, int fa) {
	if(szz(E[x]) == 1) {
		return x;
	}
	vector <int> w;
	for(int e : E[x]) if(e != fa) {
		w.pb(dfs(e, x));
	}
	for(int i=0;i+1<szz(w);i+=2) {
		int r = ask(w[i], w[i+1]);
		if(r != x) {
			output(r);
			exit(0);
		}
	}
	if(szz(w) % 2) return w.back();
	else return x;
}

void solve() {
	scanf("%d", &n);
	rep(i, n-1) {
		int x, y;
		scanf("%d%d", &x, &y);
		E[x].pb(y);
		E[y].pb(x);
	}
	if(n == 2) {
		int v = ask(1, 2);
		output(v);
		return;
	}
	int rt = -1;
	for(int i=1;i<=n;i++) if(szz(E[i]) > 1) {
		rt = i; break;
	}
	int r = dfs(rt, -1);
	if(r != rt) {
		output(ask(r, rt));
	}
	else output(r);
}

int main() {
	int t = 1; //scanf("%d", &t);
	rep(tt, t) {
		solve();
	}
	return 0;
}