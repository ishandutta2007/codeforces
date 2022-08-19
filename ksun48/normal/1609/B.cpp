#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	int score = 0;
	for(int j = 0; j + 2 < n; j++){
		if(s.substr(j, 3) == "abc") score++;
	}
	for(int i = 0; i < q; i++){
		int k;
		cin >> k;
		k--;
		char c;
		cin >> c;
		for(int j = max(0, k-2); j <= k && j + 2 < n; j++){
			if(s.substr(j, 3) == "abc") score--;
		}
		s[k] = c;
		for(int j = max(0, k-2); j <= k && j + 2 < n; j++){
			if(s.substr(j, 3) == "abc") score++;
		}
		cout << score << '\n';
	}
}