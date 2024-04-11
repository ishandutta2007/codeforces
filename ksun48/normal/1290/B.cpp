#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	int n = (int)s.size();
	vector<vector<int> > nxt(n+1, vector<int>(26, n));
	for(int i = n-1; i >= 0; i--){
		nxt[i] = nxt[i+1];
		nxt[i][s[i]-'a'] = i;
	}
	int q;
	cin >> q;
	for(int _ = 0; _ < q; _++){
		int l, r;
		cin >> l >> r;
		l--; r--;
		if(l == r){
			cout << "Yes" << '\n';
			continue;
		}
		int nc = 0;
		for(int j = 0; j < 26; j++){
			if(nxt[l][j] <= r){
				nc++;
			}
		}
		if(nc >= 3 || (nc >= 2 && s[l] != s[r])){
			cout << "Yes" << '\n';
			continue;
		} else {
			cout << "No" << '\n';
		}
	}
}