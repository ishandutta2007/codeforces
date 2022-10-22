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
llint n;
char c[205][205];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		for(int y = 1; y <= n; y++){
			for(int x = 1; x <= n; x++){
				cin >> c[x][y];
			}
		}
		
		vector<P> vec, vec2;
		if(c[1][2] == '0') vec.push_back(P(1, 2));
		if(c[2][1] == '0') vec.push_back(P(2, 1));
		if(c[n-1][n] == '1') vec.push_back(P(n-1, n));
		if(c[n][n-1] == '1') vec.push_back(P(n, n-1));
		
		if(c[1][2] == '1') vec2.push_back(P(1, 2));
		if(c[2][1] == '1') vec2.push_back(P(2, 1));
		if(c[n-1][n] == '0') vec2.push_back(P(n-1, n));
		if(c[n][n-1] == '0') vec2.push_back(P(n, n-1));
		
		if(vec.size() > 2) vec = vec2;
		cout << vec.size() << endl;
		for(int i = 0; i < vec.size(); i++) cout << vec[i].second << " " << vec[i].first << endl;
	}
	
	return 0;
}