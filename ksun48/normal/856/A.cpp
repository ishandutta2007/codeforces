#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int sums[2100000];
int main(){
	int T;
	cin >> T;
	srand(time(0));
	for(int t = 0; t < T; t++){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		int ok = 1;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < i; j++){
				if(a[i] == a[j]){
					ok = 0;
				}
			}
		}
		if(ok == 0){
			cout << "NO" << endl;
			continue;
		}
		for(int i = 0; i < 2100000; i++) sums[i] = 0;
		vector<int> ans;
		int r = 0;
		while(1){
			if(ans.size() == n) break;

			//int r = rand() << 10 + rand();
			if(r < 0) r = -r;
			r %= 1000000; r++;
			int bad = 0;
			for(int j = 0; j < n; j++){
				if(sums[r+a[j]]){
					bad = 1;
					break;
				}
			}
			if(bad) continue;
			for(int j = 0; j < n; j++){
				sums[r+a[j]] = 1;
			}
			ans.push_back(r);
		}
		cout << "YES" << endl;
		for(int i = 0; i < ans.size(); i++){
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}