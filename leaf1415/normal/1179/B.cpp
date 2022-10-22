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

llint h, w;

void calc(llint u, llint d)
{
	if(u > d) return;
	if(u == d){
		for(int i = 1; i <= w/2; i++){
			cout << u << " " << i << "\n";
			cout << u << " " << w+1-i << "\n";
		}
		if(w % 2) cout << u << " " << w/2+1 << "\n";
		return;
	}
	for(int i = 1; i <= w; i++){
		cout << u << " " << i << "\n";
		cout << d << " " << w+1-i << "\n";
	}
	calc(u+1, d-1);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w;
	calc(1, h);
	flush(cout);
	
	return 0;
}