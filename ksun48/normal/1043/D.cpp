#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	map<pair<int,int>, int> freq;
	for(int i = 0; i < m; i++){
		vector<int> a(n);
		for(int j = 0; j < n; j++){
			cin >> a[j];
			a[j]--;
			if(j > 0){
				freq[{a[j-1], a[j]}]++;
			}
		}
	}
	vector<int> next(n, -1);
	vector<int> has(n, 0);
	for(auto x : freq){
		if(x.second == m){
			next[x.first.first] = x.first.second;
			has[x.first.second] = 1;
		}
	}
	LL ans = 0;
	for(int i = 0; i < n; i++){
		if(!has[i]){
			LL x = i;
			LL v = 1;
			while(next[x] != -1){
				v++;
				x = next[x];
			}
			ans += v * (v+1) / 2;
		}
	}
	cout << ans << endl;
}