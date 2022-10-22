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

llint n, Q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i % 2) cout << 0 << " ";
			else cout << (1LL<<(i+j)) << " ";
		}
		cout << endl;
	}
	
	cin >> Q;
	llint k;
	for(int q = 0; q < Q; q++){
		cin >> k;
		
		llint i = 0, j = 0;
		cout << 1 << " " << 1 << endl;
		for(int d = 1; d <= 2*n-2; d++){
			if(k & (1LL<<d)){
				if(i % 2) i++;
				else j++;
			}
			else{
				if(i % 2) j++;
				else i++;
			}
			cout << i+1 << " " << j+1 << endl;
		}
	}
	
	return 0;
}