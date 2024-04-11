#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#define llint long long

using namespace std;

llint T;
string s, t;
llint succ[200005][26];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int z = 0; z < T; z++){
		cin >> s >> t;
		llint n = s.size();
		s = s + s;
		
		for(int i = 0; i < 26; i++) succ[2*n-1][i] = 2*n;
		for(int i = 2*n-2; i >= 0; i--){
			for(int j = 0; j < 26; j++) succ[i][j] = succ[i+1][j];
			succ[i][s[i+1]-'a'] = i+1;
		}
		llint p = n-1, ans = 0;
		for(int i = 0; i < t.size(); i++){
			p = succ[p][t[i]-'a'];
			if(p == 2*n){
				cout << -1 << endl;
				goto end;
			}
			if(p >= n) p %= n, ans++;
		}
		cout << ans << endl;
		
		end:;
	}
	
	return 0;
}