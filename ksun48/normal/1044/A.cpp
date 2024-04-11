#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> x(n);
	for(int i = 0; i < n; i++){
		cin >> x[i];
	}
	sort(x.begin(), x.end());
	x.push_back(1000000000);
	vector<int> x2s;
	for(int i = 0; i < m; i++){
		int l, r, y;
		cin >> l >> r >> y;
		if(l != 1) continue;
		x2s.push_back(r);
	}
	sort(x2s.begin(), x2s.end());
	int t = 0;
	int ans = 1 << 29;
	for(int i = 0; i < x.size(); i++){
		while(t < x2s.size() && x2s[t] < x[i]){
			t++;
		}
		ans = min(ans, i + (int)x2s.size() - t);
	}
	cout << ans << endl;
}