#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int n,a[N],k,vis[N];
vector<int> v;
int main() {
	ios::sync_with_stdio(0);
	int t;cin >> t;
	while(t--) {
		int cnt = 0;
		cin >> n >> k;
		memset(vis,0,sizeof vis);v.clear();
		for(int i = 1;i <= n;++i) {
			cin >> a[i];
			if(!vis[a[i]]) vis[a[i]] = 1,++cnt,v.push_back(a[i]);
		}
		if(cnt > k) cout << -1 << endl;
		else {
			for(int i = 1;i <= n;++i)
				if(cnt < k && !vis[i]) vis[i] = 1,++cnt,v.push_back(i);
			cout << n*k << endl;
			for(int i = 1;i <= n;++i)
				for(int j = 0;j < v.size();++j)
					cout << v[j] << ' ';
			cout << endl;
		}
	}
	return 0;
}