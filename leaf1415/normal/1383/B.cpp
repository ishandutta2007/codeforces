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
llint a[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int z = 0; z < T; z++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		llint sum = 0;
		for(int i = 1; i <= n; i++) sum ^= a[i];
		if(sum == 0){
			cout << "DRAW" << endl;
			continue;
		}
		
		llint b;
		for(int i = 40; i >= 0; i--){
			if(sum & (1LL<<i)){
				b = i;
				break;
			}
		}
		llint cnt = 0;
		for(int i = 1; i <= n; i++){
			if(a[i] & (1LL<<b)) cnt++;
		}
		
		if(cnt%4 == 1) cout << "WIN" << endl;
		else if(cnt%4 == 3 && (n-cnt)%2) cout << "WIN" << endl;
		else cout << "LOSE" << endl;
	}
	
	return 0;
}