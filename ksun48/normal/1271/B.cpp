#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(int i = 0; i < 2; i++){
		char x = "WB"[i];
		string t = s;
		vector<int> ops;
		for(int j = 0; j + 1 < n; j++){
			if(t[j] != x){
				t[j] ^= 'W' ^ 'B';
				t[j+1] ^= 'W' ^ 'B';
				ops.push_back(j+1);
			}
		}
		if(t.back() == x){
			cout << ops.size() << '\n';
			for(int a : ops){
				cout << a << ' ';
			}
			cout << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
}