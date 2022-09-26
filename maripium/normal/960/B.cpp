#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3 + 5;

int n,k1,k2;
int a[N],b[N],f[N];
signed main() {
	ios_base::sync_with_stdio(false);	cin.tie(0);
	cin >> n >> k1 >> k2;
	for (int i = 1;i <= n;++i) cin >> a[i];
	for (int i = 1;i <= n;++i) cin >> b[i];
	priority_queue<int> pq;
	for (int i = 1;i <= n;++i) pq.push(abs(a[i] - b[i]));
	for (int i = 1;i <= k1 + k2;++i) {
		int u = pq.top();
		pq.pop();
		if(u == 0) ++u;
		else --u;
		pq.push(u);
	}
	int ans = 0;
	while(!pq.empty()) {
		int u = pq.top();
		pq.pop();
		ans += u * u;
	}
	cout << ans << endl;
}