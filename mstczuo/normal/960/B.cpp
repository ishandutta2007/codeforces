# include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define all(a) a.begin(),a.end()
#define For(i, l, r) for(int i = l; i <= r; ++i)
#define rep(i, n) For(i, 0, n-1)
#define pb push_back

void rd(int &x) { scanf("%d", &x); }


vector<int> a, b;
int main() {
	int n, k1, k2;
	rd(n); rd(k1); rd(k2);
	a.resize(n);
	b.resize(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	rep(i, n) a[i] = abs(a[i] - b[i]);

	priority_queue<int> q;
	rep(i, n) q.push(a[i]);
	int k = k1 + k2;
	while(k--) {
		int x = q.top(); q.pop();
		q.push(abs(x-1));
	}
	long long ans = 0;
	while(!q.empty()) {
		int x = q.top(); q.pop();
		ans += 1ll * x * x;
	}
	cout << ans << endl;
}