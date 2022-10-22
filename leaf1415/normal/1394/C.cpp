#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

llint n;
string s[300005];
llint x[300005], y[300005], u[300005];
llint X, Y;

bool check(llint d)
{
	llint lx = 0, rx = inf, ly = 0, ry = inf;
	for(int i = 1; i <= n; i++){
		lx = max(lx, x[i] - d);
		rx = min(rx, x[i] + d);
		ly = max(ly, y[i] - d);
		ry = min(ry, y[i] + d);
	}
	if(lx > rx || ly > ry) return false;
	
	llint ru = rx-ly, lu = lx-ry;
	//cout << lu << " " << ru << endl;
	for(int i = 1; i <= n; i++){
		lu = max(lu, u[i] - d);
		ru = min(ru, u[i] + d);
	}
	if(lu > ru) return false;
	
	llint U = lu;
	if(lu == 0) U = ru;
	if(U <= rx-ry) Y = ry, X = U + ry;
	else X = rx, Y = X - U;
	
	if(X == 0 && Y == 0) return false;
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> s[i];
		for(int j = 0; j < s[i].size(); j++){
			if(s[i][j] == 'B') x[i]++;
			else y[i]++;
		}
		u[i] = x[i] - y[i];
	}
	
	//for(int i = 1; i <= n; i++) cout << x[i] << " " << y[i] << endl;
	
	llint ub = 2e6, lb = -1, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) ub = mid;
		else lb = mid;
	}
	cout << ub << endl;
	
	//cout << X << " " << Y << endl;
	
	check(ub);
	for(int i = 0; i < X; i++) cout << 'B';
	for(int i = 0; i < Y; i++) cout << 'N';
	cout << endl;
	
	return 0;
}