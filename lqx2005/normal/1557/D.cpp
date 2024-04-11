#include <bits/stdc++.h>
#define broken cerr << "running on " << __FUNCTION__ <<" "<< __LINE__ << endl
#define x first
#define y second
#define mp make_pair
#define sz(a) int((a).size())
#define par pair<int, int>
#define poly vector<int>
#define i64 long long
#define u64 unsigned long long
using namespace std;
const int N = 6e5 + 10;
int n, m;
int x[N], l[N], r[N], num[N], sum[N], tot = 0;
int dp[N], pre[N], vis[N], ans[N];
vector<int> q[N], g[N];
set<int> now;

void Adde(int u, int v) {
	g[u].push_back(v);
}

void initnum() {
	for(int i = 1; i <= m; i++) {
		num[++tot] = l[i], num[++tot] = r[i];
	}
	sort(num + 1, num + tot + 1);
	tot = unique(num + 1, num + tot + 1) - (num + 1);
	for(int i = 1; i <= m; i++) {
		l[i] = lower_bound(num + 1, num + tot + 1, l[i]) - num;
		r[i] = lower_bound(num + 1, num + tot + 1, r[i]) - num;
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> x[i] >> l[i] >> r[i];
		r[i]++;
	}
	initnum();
	for(int i = 1; i <= m; i++) {
		q[l[i]].push_back(x[i]), q[r[i]].push_back(- x[i]);
	}
	for(int i = 1; i <= tot; i++) {
		for(int &v : q[i]) {
			if(v > 0) {
				if(sum[v] == 0) now.insert(v);
				sum[v]++;
			} else {
				sum[- v]--;
				if(sum[- v] == 0) {
					now.erase(- v);
				}
			}
		}
		for(int &v : q[i]) {
			if(v > 0) {
				auto it = now.lower_bound(v);
				if(it != now.begin()) it--, Adde(v, *it);
				it = now.upper_bound(v);
				if(it != now.end()) Adde(*it, v);
			}
		}
	}
	int rt = -1;
	for(int i = 1; i <= n; i++) {
		dp[i] = 1;
		for(int &v : g[i]) {
			if(dp[v] + 1 > dp[i]) {
				pre[i] = v;
				dp[i] = dp[v] + 1;
			}
		}
		if(rt == -1 || dp[rt] < dp[i]) rt = i;
	} 
	for(; rt; rt = pre[rt]) {
		vis[rt] = 1;
	}
	int len = 0;
	for(int i = 1; i <= n; i++) if(!vis[i]) ans[++len] = i;
	cout << len << endl;
	for(int i = 1; i <= len; i++) {
		cout << ans[i] <<" ";
	}
	cout << endl;
    return 0;
}