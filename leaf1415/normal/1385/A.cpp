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
llint a, b, c;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> a >> b >> c;
		llint m = max(a, max(b, c));
		if(a == m && b == m && c == m){
			cout << "YES" << endl;
			cout << m << " " << m << " " << m << endl;
			continue;
		}
		if(a == m && b == m){
			cout << "YES" << endl;
			cout << m << " " << c << " " << 1 << endl;
			continue;
		}
		if(a == m && c == m){
			cout << "YES" << endl;
			cout << b << " " << m << " " << 1 << endl;
			continue;
		}
		if(b == m && c == m){
			cout << "YES" << endl;
			cout << a << " " << 1 << " " << m << endl;
			continue;
		}
		cout << "NO" << endl;
	}
	
	return 0;
}