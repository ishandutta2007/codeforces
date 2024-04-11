#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	int cur = 1100;
	vector<string> ans(2200, string(sum, ' '));
	int s = 0;
	for(int i = 0; i < n; i++){
		if(i % 2 == 0){
			for(int j = 0; j < a[i]; j++){
				if(j > 0) cur--;
				ans[cur][s++] = '/';
			}
		} else {
			for(int j = 0; j < a[i]; j++){
				if(j > 0) cur++;
				ans[cur][s++] = '\\';
			}
		}
	}
	for(string x : ans){
		if(x != string(sum, ' ')){
			cout << x << '\n';
		}
	}
}