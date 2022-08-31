#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	int k;
	cin >> k;
	s += string(k, '*');
	int ans = 0;
	for(int i = 0; i <= (int)s.size(); i++){
		for(int j = 0; i + 2 * j <= s.size(); j++){
			string t1 = s.substr(i, j);
			string t2 = s.substr(i+j, j);
			bool works = true;
			for(int q = 0; q < j; q++){
				if(t1[q] == '*' || t2[q] == '*' || t1[q] == t2[q]){

				} else {
					works = false;
				}
			}
			if(works) ans = max(ans, j);
		}
	}
	cout << ans * 2;
}