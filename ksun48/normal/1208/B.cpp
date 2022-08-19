#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	int ans = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int j = 0; j <= n; j++){
		set<int> els;
		bool ok = true;
		for(int i = 0; i < j; i++){
			if(els.count(a[i])){
				els.insert(a[i]);
				ok = false;
			}
			els.insert(a[i]);
		}
		if(!ok) continue;
		int num = j;
		ans = max(ans, num);
		for(int r = n-1; r >= j; r--){
			if(els.count(a[r])) break;
			els.insert(a[r]);
			num += 1;
			ans = max(ans, num);
		}
	}
	cout << n - ans << '\n';
}