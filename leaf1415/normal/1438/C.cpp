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

llint T;
llint h, w;
llint a[105][105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> h >> w;
		rep(y, 1, h){
			rep(x, 1, w){
				cin >> a[x][y];
			}
		}
		rep(y, 1, h){
			rep(x, 1, w){
				if(a[x][y] % 2 != (x+y)%2) a[x][y]++;
			}
		}
		rep(y, 1, h){
			rep(x, 1, w){
				cout << a[x][y] << " ";
			}
			cout << endl;
		}
	}
	
	return 0;
}