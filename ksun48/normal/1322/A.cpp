#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cur = 0;
	vector<int> z = {0};
	int q = 0;
	for(char x : s){
		if(x == '('){
			cur++;
		} else {
			cur--;
		}
		q++;
		if(cur >= 0) z.push_back(q);
	}
	if(cur != 0){
		cout << -1 << '\n';
		return 0;
	}
	int ans = 0;
	for(int i = 0; i + 1 < (int)z.size(); i++){
		if(z[i] + 1 < z[i+1]){
			ans += z[i+1] - z[i];
		}
	}
	cout << ans << '\n';
}