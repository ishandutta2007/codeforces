#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i]--;
	}
	vector<vector<int> > idlers(k);
	vector<LL> b(n);
	for(int i = 0; i < n; i++){
		cin >> b[i];
		idlers[a[i]].push_back(b[i]);
	}
	int need = 0;
	vector<LL> bad;
	for(int i = 0; i < k; i++){
		if(idlers[i].size() == 0){
			need++;
		} else {
			sort(idlers[i].begin(), idlers[i].end());
			reverse(idlers[i].begin(), idlers[i].end());
			for(int j = 1; j < idlers[i].size(); j++){
				bad.push_back(idlers[i][j]);
			}
		}
	}
	sort(bad.begin(), bad.end());
	bad.resize(need);
	LL ans = 0;
	for(LL x : bad){
		ans += x;
	}
	cout << ans << '\n';
}