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
llint l, r, m;

bool output(llint a, llint d)
{
	if(abs(d) > r-l) return false;
	
	llint b, c;
	if(d >= 0) b = d+l, c = l;
	else b = r+d, c = r;
	cout << a << " " << b << " " << c << endl;
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> l >> r >> m;
		
		for(llint i = l; i <= r; i++){
			if(m/i > 0 && output(i, m - m/i*i)) break;
			if(output(i, m - (m+i-1)/i*i)) break;
		}
	}
	
	return 0;
}