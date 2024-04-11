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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

llint n;

llint check(llint x)
{
	llint res, res2;
	cout << "? " << x << endl;
	cin >> res;
	cout << "? " << x+n/2 << endl;
	cin >> res2;
	return res - res2;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	if(n/2%2){
		cout << "! -1" << endl;
		return 0;
	}
	
	llint x = check(1);
	if(x == 0){
		cout << "!" << " " << 1 << endl;
		return 0;
	}
	llint sgn = 1;
	if(x < 0) sgn = -1;
	
	llint ub = n/2+1, lb = 1, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		llint res = check(mid) * sgn;
		if(res >= 0) lb = mid;
		else ub = mid;
	}
	cout << "!" << " " << lb << endl;
	
	return 0;
}