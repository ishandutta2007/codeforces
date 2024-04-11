#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

int n;
char In[200020];
int dp[200020];
void solve() {
	scanf("%d", &n);
	scanf("%s", In + 1);
	int ans = 1e9;
	rep(c, 4) {
		auto upd = [](int &a, int b) { if(a > b) a = b; };
		for(int i=1;i<=n;i++) {
			dp[i] = 1e9;
			if(i >= 2) {
				int r = (In[i] != 'L') + (In[i-1] != 'R');
				upd(dp[i], dp[i-2] + r);
			}
			if(i >= 3) {
				int r = (In[i] != 'L') + (In[i-1] != 'R') + (In[i-2] != 'R');
				upd(dp[i], dp[i-3] + r);
				r = (In[i] != 'L') + (In[i-1] != 'L') + (In[i-2] != 'R');
				upd(dp[i], dp[i-3] + r);
			}
			if(i >= 4) {
				int r = (In[i] != 'L') + (In[i-1] != 'L') + (In[i-2] != 'R') + (In[i-3] != 'R');
				upd(dp[i], dp[i-4] + r);
			}
		}
		ans = min(ans, dp[n]);
		rotate(In+1, In+2, In+1+n);
	}
	printf("%d\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	for(int t=1;t<=T;t++) {
		solve();
	}
	return 0;
}