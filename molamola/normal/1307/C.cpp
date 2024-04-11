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

char A[100010];

void solve() {
	scanf("%s", A + 1);
	int n = (int)strlen(A+1);
	ll c1[30] = {}, c2[30][30] = {};
	for(int i=1;i<=n;i++) {
		int x = A[i] - 'a';
		rep(j, 26) c2[j][x] += c1[j];
		c1[x]++;
	}
	ll ans = *max_element(c1, c1 + 26);
	rep(i, 26) rep(j, 26) ans = max(ans, c2[i][j]);
	printf("%lld\n", ans);
}

int main() {
	int T = 1; //scanf("%d", &T);
	for(int t=1;t<=T;t++) {
		solve();
	}
	return 0;
}