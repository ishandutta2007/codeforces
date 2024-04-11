#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define llint long long

using namespace std;

llint Q;
llint n, k;
string s;
llint sum[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> n >> k;
		cin >> s;
		s = "#" + s;
		for(int i = 1; i <= n; i++){
			if(s[i] == 'R') s[i] = '0';
			if(s[i] == 'G') s[i] = '1';
			if(s[i] == 'B') s[i] = '2';
		}
		
		llint ans = 1e9;
		for(int i = 0; i < 3; i++){
			for(int j = 1; j <= n; j++){
				sum[j] = sum[j-1];
				if((i+j)%3 != s[j]-'0') sum[j]++;
			}
			for(int j = k; j <= n; j++) ans = min(ans, sum[j]-sum[j-k]);
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}