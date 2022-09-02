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

const int X = 5e8;
int ans[5050];

void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	int mx = 0;
	for(int i=3;i<=n;i++) mx += (i-1) / 2;
	if(mx < m) {
		puts("-1");
		return;
	}
	int tm = m;
	ans[1] = 1, ans[2] = 2;
	for(int i=3;i<=n;i++) {
		int v = (i-1) / 2;
		if(tm >= v) {
			tm -= v;
			ans[i] = i;
		}
		else {
			ans[i] = i-1 + i-2*tm;
			for(int j=i+1;j<=n;j++) ans[j] = X + (j - i) * 11000;
			break;
		}
	}
	for(int i=1;i<=n;i++) printf("%d ", ans[i]); puts("");
}

int main() {
	int t = 1; //scanf("%d", &t);
	rep(tt, t) {
		solve();
	}
	return 0;
}