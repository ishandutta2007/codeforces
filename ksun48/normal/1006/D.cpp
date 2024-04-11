#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	int ans = 0;
	for(int i = 0; i < n; i++){
		int j = n-1-i;
		if(i > j) break;
		if(i <= j){
			string g;
			g += s1[i];
			g += s2[i];
			if(i < j) g += s1[j];
			if(i < j) g += s2[j];
			sort(g.begin(), g.end());
			if(i == j) g += "ZZ";
			if(g[0] == g[1] && g[2] == g[3]){
				ans += 0;
			} else if (g[0] == g[1] || g[1] == g[2] || g[2] == g[3]){
				ans += 1;
				if(i < j && s1[i] == s1[j] && s1[i] != s2[i] && s1[j] != s2[j]){
					ans += 1;
				}
			} else {
				ans += 2;
			}
		}
	}
	cout << ans << '\n';
}