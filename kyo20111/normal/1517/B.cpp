#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, a[111][111], b[111][111], mn[111];

void solve(){
	cin >> n >> m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> a[i][j];

	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) b[i][j] = 0;

	set<tuple<int, int, int>> s;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) s.insert({a[i][j], i, j});

	for(int i=1;i<=m;i++){
		auto [c, x, y] = *s.begin();
		b[x][i] = c;
		s.erase(s.begin());
	}

	while(!s.empty()){
		auto [c, x, y] = *s.begin();
		for(int i=1;i<=m;i++){
			if(!b[x][i]){
				b[x][i] = c;
				break;
			}
		}
		s.erase(s.begin());
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cout << b[i][j] << " ";
		cout << "\n";
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int tc = 1; cin >> tc;
	while(tc--) solve();
}