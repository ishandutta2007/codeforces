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

llint T;
llint h, w;
llint X[55], Y[55];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> h >> w;
		
		for(int i = 1; i <= w; i++) X[i] = 0;
		for(int i = 1; i <= h; i++) Y[i] = 0;
		
		llint a;
		for(int y = 1; y <= h; y++){
			for(int x = 1; x <= w; x++){
				cin >> a;
				if(a) X[x]++, Y[y]++;
			}
		}
		
		llint cntX = 0, cntY = 0;
		for(int i = 1; i <= w; i++) if(X[i] == 0) cntX++;
		for(int i = 1; i <= h; i++) if(Y[i] == 0) cntY++;
		
		if(min(cntX, cntY)%2) cout << "Ashish" << endl;
		else cout << "Vivek" << endl;
	}
	
	return 0;
}