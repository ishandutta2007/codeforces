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
llint n, l, r;
llint p;

void calc(llint x)
{
	if(n == x) return;
	llint len = 2*(n-x);
	if(p > r || p+len-1 < l) p += len;
	else{
		for(int i = 0; i < len; i++){
			if(p >= l && p <= r){
				//cout << blen << endl;
				if(i % 2 == 0) cout << x << " ";
				else cout << i/2 + x+1 << " ";
			}
			p++;
		}
	}
	calc(x+1);
	
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> l >> r;
		
		p = 1;
		calc(1);
		if(p == r) cout << 1;
		cout << endl;
	}
	flush(cout);
	
	return 0;
}