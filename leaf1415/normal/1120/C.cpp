#include <iostream>
#include <string>
#include <algorithm>
#define llint long long

using namespace std;

llint n, a, b;
string s, t;
llint dp[5005];
int z[5005];

void z_algorithm(string s, int z[])
{
	z[0] = s.size();
	
	int x = 0, y = 0;
	for(int i = 1; i < s.size(); i++){
		if(i > y){
			z[i] = 0;
			for(int j = 0; j < s.size(); j++){
				if(i+j > s.size() || s[i+j] != s[j]) break;
				z[i]++;
			}
			x = i, y = i + z[i] - 1;
		}
		else if(i + z[i-x] <= y) z[i] = z[i-x];
		else{
			z[i] = y-i+1;
			for(int j = y-i+1; j < s.size(); j++){
				if(i+j > s.size() || s[i+j] != s[j]) break;
				z[i]++;
			}
			x = i, y = i + z[i] - 1;
		}
	}
}

int main(void)
{
	cin >> n >> a >> b;
	cin >> s;
	s = "$" + s;
	
	
	dp[1] = a;
	for(int i = 2; i <= n; i++){
		dp[i] = dp[i-1] + a;
		
		t = s.substr(1, i);
		reverse(t.begin(), t.end());
		z_algorithm(t, z);
		int mx = 0;
		for(int j = 0; j < t.size(); j++) mx = max(mx, min(j, z[j]));
		
		if(mx > 0) dp[i] = min(dp[i], dp[i-mx] + b);
	}
	cout << dp[n] << endl;
	
	return 0;
}