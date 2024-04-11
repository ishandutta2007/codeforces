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
llint n;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		
		if(n <= 30){
			cout << "NO" << endl;
			continue;
		}
		if(n == 36 || n == 40 || n == 44){
			cout << "YES" << endl;
			cout << 6 << " " << 10 << " " << 15 << " " << n - 31 << endl;
			continue;
		}
		cout << "YES" << endl;
		cout << 6 << " " << 10 << " " << 14 << " " << n - 30 << endl;
	}
	
	return 0;
}