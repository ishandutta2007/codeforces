#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	vector<int> par(n);
	par[0] = -1;
	vector<LL> s(n);
	for(int i = 1; i < n; i++){
		cin >> par[i];
		par[i]--;
	}
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	vector<vector<int> >xc(n);
	for(int i = 1; i < n; i++){
		if(s[i] == -1) continue;
		if(s[par[par[i]]] > s[i]){
			cout << -1 << '\n';
			return 0;
		}
	}
	LL ans = 0;
	ans += s[0];
	for(int i = 1; i < n; i++){
		if(s[i] == -1) continue;
		xc[par[i]].push_back(i);
	}
	for(int i = 0; i < n; i++){
		if(xc[i].size() > 0){
			LL minc = 1500500500;
			for(int a : xc[i]){
				minc = min(minc, s[a] - s[par[i]]);
			}
			ans += minc;
			for(int a : xc[i]){
				ans += s[a] - s[par[i]] - minc;
			}
		}
	}
	cout << ans << '\n';
}