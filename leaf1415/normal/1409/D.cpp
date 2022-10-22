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
llint n, s;

llint get(llint x)
{
	llint ret = 0;
	for(;x;x/=10) ret += x%10;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> s;
		
		if(get(n) <= s){
			cout << 0 << endl;
			continue;
		}
		llint mul = 1;
		while(1){
			mul *= 10;
			llint x = (n+mul-1)/mul*mul;
			if(get(x) <= s){
				cout << x - n << endl;
				break;
			}
		}
	}
	
	return 0;
}