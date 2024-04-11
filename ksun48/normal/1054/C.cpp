#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	vector<int> l(n);
	vector<int> r(n);
	vector<int> ans(n);
	for(int i = 0; i < n; i++) cin >> l[i];
	for(int i = 0; i < n; i++) cin >> r[i];
	for(int i = 0; i < n; i++) ans[i] = n - l[i] - r[i];
	for(int i = 0; i < n; i++){
		int lreal = 0;
		int rreal = 0;
		for(int j = 0; j < i; j++){
			if(ans[j] > ans[i]) lreal++;
		}
		for(int j = i+1; j < n; j++){
			if(ans[j] > ans[i]) rreal++;
		}
		if(lreal != l[i] || rreal != r[i]){
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
	for(int i = 0; i < n; i++){
		cout << ans[i] << " ";
	}
	cout << endl;
}