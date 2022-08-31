#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	long long ns = 0;
	long long tot = 0;
	for(int i = 0; i < n; i++){
		int z = a[i];
		tot += z;
		if(i & 1){
			ns += (z + 1) / 2;
		} else {
			ns += z / 2;
		}
	}
	cout << min(ns, tot - ns) << '\n';
}