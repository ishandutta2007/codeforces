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
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll h, w;
char c[105][105];

bool check()
{
	if(w % 3) return false;
	if(c[0][0] == c[w/3][0] || c[w/3][0] == c[w/3*2][0] || c[w/3*2][0] == c[0][0]) return false;
	rep(y, 0, h-1) rep(x, 0, w-1){
		if(c[x][y] != c[x/(w/3)*(w/3)][0]) return false;
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w;
	rep(y, 0, h-1) rep(x, 0, w-1) cin >> c[x][y];
	
	if(check()){
		cout << "YES" << endl;
		return 0;
	}
	
	rep(y, 0, 100) rep(x, 0, 100) if(x < y) swap(c[x][y], c[y][x]);
	swap(h, w);
	
	if(check()){
		cout << "YES" << endl;
		return 0;
	}
	
	cout << "NO" << endl;
	
	return 0;
}