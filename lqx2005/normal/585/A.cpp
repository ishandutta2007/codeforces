#include<bits/stdc++.h>

#define sz(a) int((a).size())
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef double db;
const int N = 4000 + 10;
int n;
ll v[N], p[N], d[N];
int id[N], tmp[N];
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> v[i] >> d[i] >> p[i];
	int tot = 0;
	vector<int> ans;
	for(int i = 1; i <= n; i++) id[++tot] = i;
	for(; tot > 0; ) {
		int u = id[1];
		ans.push_back(u);
		for(int j = 2; j <= tot; j++) {
			p[id[j]] -= max(v[u] - (j - 2), 0ll);
		}
		ll sum = 0;
		int totid = 0;
		for(int j = 2; j <= tot; j++) {
			p[id[j]] -= sum;
			if(p[id[j]] < 0) {
				sum += d[id[j]];
			} else {
				tmp[++totid] = id[j];
			}
		}
		for(int j = 1; j <= totid; j++) id[j] = tmp[j];
		tot = totid;
	}
	cout << sz(ans) << endl;
	for(int x : ans) cout << x <<" ";
	cout << endl;
	return 0;
}