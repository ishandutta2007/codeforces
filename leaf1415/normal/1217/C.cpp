#include <iostream>
#include <string>
#define llint long long

using namespace std;

llint T;
string s;
llint cnt[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> s;
		llint n = s.size(), x = 0;
		for(int i = 0; i < n; i++){
			cnt[i] = x;
			if(s[i] == '0') x++;
			else x = 0;
		}
		
		llint ans = 0;
		for(int i = n-1; i >= 0; i--){
			llint sum = 0;
			for(int j = 0; j < 19; j++){
				if(i-j < 0) break;
				sum += (s[i-j]-'0') << j;
				if(s[i-j] == '1' && sum-(j+1) <= cnt[i-j]) ans++;
			}
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}