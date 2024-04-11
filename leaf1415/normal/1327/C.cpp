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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)

using namespace std;

llint h, w, k;
string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w >> k;
	llint x, y;
	for(int i = 1; i <= k; i++) cin >> x >> y;
	for(int i = 1; i <= k; i++) cin >> x >> y;
	
	for(int i = 1; i <= h-1; i++) s += "U";
	for(int i = 1; i <= w-1; i++) s += "L";
	
	x = 1, y = 1;
	while(x <= w){
		if(x % 2){
			if(y < h) y++, s += "D";
			else x++, s += "R";
		}
		else{
			if(y > 1) y--, s += "U";
			else x++, s += "R";
		}
	}
	cout << s.size() << endl;
	cout << s << endl;
	
	return 0;
}