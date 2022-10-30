# include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define all(a) a.begin(),a.end()
#define For(i, l, r) for(int i = l; i <= r; ++i)
#define rep(i, n) For(i, 0, n-1)
#define pb push_back

void rd(int &x) { scanf("%d", &x); }

int cnt[1002];
int main() {
	int n, m, x; rd(n); rd(m);
	rep(i, m) rd(x), cnt[x]++;
	int ans = cnt[1];
	For(i, 1, n) ans = min(ans, cnt[i]);
	cout << ans << endl;
	return 0;
}