#include <iostream>
#include <string>
#include <cstdlib>
#define llint long long

using namespace std;

llint sx, sy, gx, gy;
llint n;
string s;
llint dx, dy;

bool check(llint m)
{
	llint x = dx * (m/n), y = dy * (m/n);
	for(int i = 0; i < m%n; i++){
		if(s[i] == 'L') x--;
		if(s[i] == 'R') x++;
		if(s[i] == 'U') y++;
		if(s[i] == 'D') y--;
	}
	return abs(x-gx)+abs(y-gy) <= m;
}

int main(void)
{
	cin >> sx >> sy >> gx >> gy;
	gx -= sx, gy -= sy;
	cin >> n;
	cin >> s;
	
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'L') dx--;
		if(s[i] == 'R') dx++;
		if(s[i] == 'U') dy++;
		if(s[i] == 'D') dy--;
	}
	
	llint ub = 1e18, lb = -1, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) ub = mid;
		else lb = mid;
	}
	if(ub > 5e17) ub = -1;
	cout << ub << endl;
	
	return 0;
}