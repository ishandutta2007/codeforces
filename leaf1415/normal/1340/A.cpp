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
llint p[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 1; t <= T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> p[i];
		
		llint r = n+1;
		for(int i = 1; i <= n; i++){
			llint l = p[i];
			for(int j = 0; j < r-l; j++){
				if(p[i+j] != l+j){
					cout << "No" << "\n";
					goto end;
				}
			}
			i += r-l-1;
			r = l;
		}
		cout << "Yes" << "\n";
		end:;
	}
	
	return 0;
}