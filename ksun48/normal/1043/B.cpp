#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	vector<LL> a(n);
	vector<LL> diff(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		diff[i] = a[i];
		if(i > 0) diff[i] -= a[i-1];
	}
	vector<int> ans;
	for(int l = 1; l <= n; l++){
		int ok = 1;
		for(int i = 0; i + l < n; i++){
			if(diff[i] != diff[i+l]){
				ok = 0;
			}
		}
		if(ok) ans.push_back(l);
	}
	cout << ans.size() << endl;
	for(int x : ans){
		cout << x << " ";
	}
	cout << endl;
}