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
vector<llint> ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		n--;
		
		ans.clear();
		for(llint i = 0; ; i++){
			llint mul = 1LL<<i;
			if(n >= mul && n <= mul*2){
				ans.push_back(n-mul);
				break;
			}
			if(n > mul*2 && n < mul*4){
				ans.push_back(n/2-mul);
				ans.push_back(n%2);
				break;
			}
			n -= mul*2;
			ans.push_back(mul);
		}
		cout << ans.size() << endl;
		for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
	}
	
	return 0;
}