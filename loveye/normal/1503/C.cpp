#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5,INF = 0xfeeddeadbeef;
int n,ans;
struct Node {
	int a,c;
	inline bool operator < (const Node &o) {
		return a < o.a;
	}
} p[N];
struct BIT {
	int c[N];
	inline void add(int x,int v) {
		for(;x <= n;x += x & -x) c[x] = min(c[x],v);
	}
	inline int ask(int x) {
		int res = INF;
		for(;x;x -= x & -x) res = min(res,c[x]);
		return res;
	}
} T1,T2;
int dp[N];
signed main() {
	cin >> n;
	for(int i = 1;i <= n;++i)
		cin >> p[i].a >> p[i].c,ans += p[i].c,T1.c[i] = T2.c[i] = INF;
	sort(p+1,p+n+1);
	for(int i = n;i >= 1;--i) {
		int l = 1,r = n;
		while(l < r) {
			int mid = l + r + 1 >> 1;
			if(p[mid].a <= p[i].a + p[i].c) l = mid;
			else r = mid-1;
		}
		if(i == n) dp[i] = 0;
		else dp[i] = min(T1.ask(l),T2.ask(n-l) - p[i].a - p[i].c);
		T1.add(i,dp[i]);
		T2.add(n-i+1,dp[i] + p[i].a);
	}
	cout << ans + dp[1] << endl;
	return 0;
}