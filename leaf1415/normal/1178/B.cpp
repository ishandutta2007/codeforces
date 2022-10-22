#include <iostream>
#include <vector>
#include <string>
#define llint long long

using namespace std;

int n;
string s;
llint l[1000005], r[1000005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	n = s.size();
	s = "#" + s;
	
	for(int i = 1; i < n; i++){
		l[i] = l[i-1];
		if(s[i] == 'v' && s[i+1] == 'v') l[i]++;
	}
	for(int i = n-1; i >= 1; i--){
		r[i] = r[i+1];
		if(s[i] == 'v' && s[i+1] == 'v') r[i]++;
	}
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		if(s[i] == 'o' && i-2 >= 0 && i+1 <= n-1) ans += l[i-2] * r[i+1];
	}
	cout << ans << endl;
	
	return 0;
}