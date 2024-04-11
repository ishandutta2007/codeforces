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
llint n, x, y;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> x >> y;
		set<llint> S;
		for(int i = 1; i*i <= (y-x); i++){
			if((y-x)%i == 0) S.insert(i), S.insert((y-x)/i);
		}
		llint d;
		for(auto it = S.begin(); it != S.end(); it++){
			if((y-x)/(*it)+1 <= n){
				d = *it;
				break;
			}
		}
		llint a = max(y-(n-1)*d, y % d);
		if(a == 0) a = d;
		for(int i = 0; i < n; i++) cout << a+i*d << " "; cout << endl;
	}
	
	return 0;
}