#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n,m;
int a[N],b[N],w[N],f[N];
vector<int> v[N],bit[N];

void upd(int t,int x,int y) {
	for (;x < bit[t].size();x += x & -x) bit[t][x] = max(bit[t][x],y);
}

int get(int t,int x) {
	int ret = 0;
	for (;x > 0;x -= x & -x) ret = max(ret,bit[t][x]);
	return ret;
}
 
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= m;++i) {
		cin >> a[i] >> b[i] >> w[i];
		v[a[i]].push_back(w[i]);
		v[b[i]].push_back(w[i]);
	}
	for (int i = 1;i <= n;++i) {
		sort(v[i].begin(),v[i].end());
		bit[i].assign(v[i].size() + 5,0);
	}
	
	int ans = 0;
	for (int i = 1;i <= m;++i) {
		int id;
		id = lower_bound(v[a[i]].begin(),v[a[i]].end(),w[i]) - v[a[i]].begin();
		f[i] = get(a[i],id) + 1;
		id = lower_bound(v[b[i]].begin(),v[b[i]].end(),w[i]) - v[b[i]].begin() + 1;
		upd(b[i],id,f[i]);
		ans = max(ans,f[i]);
	}
	cout << ans << endl;
}