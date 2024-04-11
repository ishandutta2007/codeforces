#include <iostream>
#include <string>
#define llint long long

using namespace std;

llint a, b;
string s, t;
llint d[1000005], sum[1000005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s >> t;
	a = s.size(), b = t.size();
	s = "#" + s, t = "#" + t;
	
	for(int i = 1; i < a; i++) d[i] = s[i+1] - s[i];
	for(int i = 1; i <= a; i++) sum[i] = sum[i-1] + d[i];
	
	llint ans = 0, cnt = 0;
	for(int i = 1; i <= b; i++){
		if(s[i] != t[i]) cnt++;
	}
	if(cnt%2 == 0) ans++;
	for(int i = 1; i <= a-b; i++){
		if((sum[i+b-1] - sum[i-1]) % 2) cnt++;
		if(cnt%2 == 0) ans++;
	}
	cout << ans << endl;
	return 0;
}