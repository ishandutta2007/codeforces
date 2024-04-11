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
llint a[105];

bool check()
{
	llint sum = 0, mx = 0;
	for(int i = 1; i <= n; i++){
		sum += a[i];
		mx = max(mx, a[i]);
	}
	return sum < mx*2;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		llint sum = 0;
		for(int i = 1; i <= n; i++) sum += a[i];
		
		if(sum % 2 == 0){
			if(check()) cout << "T" << endl;
			else cout << "HL" << endl;
			continue;
		}
		cout << "T" << endl;
	}
	
	return 0;
}