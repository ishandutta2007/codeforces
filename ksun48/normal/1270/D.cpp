#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> res(k+1);
	for(int i = 0; i <= k; i++){
		cout << '?';
		for(int j = 0; j <= k; j++){
			if(i == j) continue;
			cout << ' ' << j+1;
		}
		cout << '\n';
		cout << flush;
		int pos;
		cin >> pos;
		cin >> res[i];
	}
	sort(res.begin(), res.end());
	for(int i = 0; i < k; i++){
		if(res[i] != res[i+1]){
			cout << '!' << ' ' << k - i << '\n';
			return 0;
		}
	}
}