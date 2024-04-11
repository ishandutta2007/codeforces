#include <iostream>
#include <string>
#include <stdlib.h>
#define llint long long

using namespace std;

llint n;
string s;
llint x, y;
llint xsum[200005], ysum[200005];

int main(void)
{
	cin >> n;
	cin >> s;
	cin >> x >> y;
	
	if(abs(x)+abs(y) > s.size() || abs(x+y)%2 != s.size()%2){
		cout << -1 << endl;
		return 0;
	}
	
	s = "#" + s;
	for(int i = 1; i <= n; i++){
		xsum[i] = xsum[i-1], ysum[i] = ysum[i-1];
		if(s[i] == 'L') xsum[i]--;
		if(s[i] == 'R') xsum[i]++;
		if(s[i] == 'D') ysum[i]--;
		if(s[i] == 'U') ysum[i]++;
	}
	llint px = xsum[n], py = ysum[n];
	
	if(px == x && py == y){
		cout << 0 << endl;
		return 0;
	}
	
	llint ans = 1e18;
	for(int i = 1; i <= n; i++){
		llint ub = n+1, lb = i-1, mid;
		while(ub-lb>1){
			mid = (ub+lb)/2;
			llint j = mid;
			llint cx = px - (xsum[j]-xsum[i-1]), cy = py - (ysum[j]-ysum[i-1]);
			if(abs(cx-x)+abs(cy-y) <= j-i+1) ub = mid;
			else lb = mid;
		}
		if(ub <= n) ans = min(ans, ub-i+1);
	}
	cout << ans << endl;
	
	return 0;
}