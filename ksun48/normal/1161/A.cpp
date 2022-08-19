#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(k);
	for(int i = 0; i < k; i++){
		cin >> a[i];
		a[i]--;
	}
	vector<int> first_occ(n, k+1);
	for(int i = k-1; i >= 0; i--){
		first_occ[a[i]] = i;
	}
	vector<int> last_occ(n, -1);
	for(int i = 0; i < k; i++){
		last_occ[a[i]] = i;
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		if(last_occ[i] == -1) ans++;
	}
	for(int i = 0; i + 1 < n; i++){
		if(last_occ[i] < first_occ[i+1]) ans++;
		if(last_occ[i+1] < first_occ[i]) ans++;
	}
	cout << ans << '\n';
}