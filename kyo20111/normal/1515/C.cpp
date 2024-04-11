#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, x, a[100100], ans[100100];
pair<int, int> p[100100];

void solve(){
	cin >> n >> m >> x;
	for(int i=1;i<=n;i++) cin >> a[i], p[i] = {a[i], i};
	sort(p+1, p+1+n, greater<>());

	set<pair<int, int>> s;
	for(int i=1;i<=m;i++) s.insert({0, i});

	for(int i=1;i<=n;i++){
		auto [x, id] = p[i];

		auto [c, u] = *s.begin();
		s.erase(s.begin());
		ans[id] = u;
		s.insert({c + x, u});
	}

	if((*prev(s.end())).first - (*s.begin()).first > x){
		cout << "NO";
	}else{
		cout << "YES\n";
		for(int i=1;i<=n;i++) cout << ans[i] << " ";
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int tc = 1; cin >> tc;
	while(tc--) solve(), cout << "\n";
}