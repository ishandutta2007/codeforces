#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
long long ans;
char mp[N][N];
int main() {
	ios::sync_with_stdio(0);
	int t;cin >> t;
	while(t--) {
		ans = 0;
		int n,m,x,y;
		cin >> n >> m >> x >> y;
		for(int i = 1;i <= n;++i)
			for(int j = 1;j <= m;++j)
				cin >> mp[i][j];
		if(y > 2*x) y = 2*x;
		for(int i = 1;i <= n;++i) {
			for(int j = 1;j <= m;++j)
				if(mp[i][j] == '.') {
					if(j != m && mp[i][j+1] == '.') ans += y,++j;
					else ans += x;
				}
		}
		cout << ans << endl;
	}
	return 0;
}