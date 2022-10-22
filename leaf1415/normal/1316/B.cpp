#include <iostream>
#include <string>
#include <algorithm>
#define llint long long

using namespace std;

llint T;
llint n;
string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> s;
		
		string ans = "~"; llint ans_i = -1;
		for(int i = 1; i <= n; i++){
			string t = s.substr(0, i-1);
			if((n+i) % 2 == 0) reverse(t.begin(), t.end());
			t = s.substr(i-1) + t;
			if(t < ans){
				ans = t;
				ans_i = i;
			}
		}
		cout << ans << "\n";
		cout << ans_i << "\n";
	}
	flush(cout);
	
	return 0;
}