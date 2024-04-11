#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	LL n;
	cin >> n;
	LL s = 0;
	while(s*s < n) s++;
	vector<LL> ans;
	for(LL a = s-1; a >= 0; a--){
		for(LL b = 0; b < s; b++){
			LL num = a * s + b + 1;
			if(num >= 1 && num <= n){
				ans.push_back(num);
			}
		}
	}
	assert(ans.size() == n);
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	cout << '\n';
}