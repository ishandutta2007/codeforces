#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int n,q;
int a[N];
vector<int> vals;
bool have[1 << 20];
vector<pair<int,int> > data[N];
int ans[N];

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(0);
	cin >> n >> q;
	for (int i = 1;i <= n;++i) cin >> a[i];
	for (int i = 1;i <= q;++i) {
		int l,x;	cin >> l >> x;
		data[l].push_back(make_pair(x,i));
	}
	
	vals.push_back(0);
	have[0] = true;
	int cur = 1;
	for (int i = 1;i <= n;++i) {
		if (have[a[i]]) cur = 1LL * cur * 2 % mod;
		else {
			int sz = vals.size();
			for (int j = 0;j < sz;++j) {
				have[vals[j] ^ a[i]] = true;
				vals.push_back(vals[j] ^ a[i]);
			}
		}
		
		for (int j = 0;j < data[i].size();++j) {
			int x = data[i][j].first;
			int id = data[i][j].second;
			if (have[x]) ans[id] = cur;
			else ans[id] = 0;
		}
	}
	
	for (int i = 1;i <= q;++i) cout << ans[i] << endl;
}