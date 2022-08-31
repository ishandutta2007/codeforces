#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<pair<int,int> > f;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		f.push_back({a[i], i});
	}
	sort(f.begin(), f.end());
	reverse(f.begin(), f.end());
	vector<int> who(n, -1);
	for(int i = 0; i < n; i++){
		int idx = f[i].second;
		int aval = a[idx];
		who[idx] = 0;
		for(int j = idx % aval; j < n; j += aval){
			if(a[j] <= a[idx]) continue;
			if(who[j] == 0){
				who[idx] = 1;
			}
		}
	}
	for(int i = 0; i < n; i++){
		cout << (char)('A' + 1 - who[i]);
	}
	cout << '\n';
}