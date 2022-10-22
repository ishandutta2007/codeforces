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
char c[9][9];
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				cin >> c[i][j];
			}
		}
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				if(c[i][j] == '1') c[i][j] = '2';
			}
		}
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				cout << c[i][j];
			}
			cout << "\n";
		}
	}
	flush(cout);
	
	return 0;
}