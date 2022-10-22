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
llint n, k;
llint a[100005];
bool used[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> k;
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		if(n == 1){
			if(a[1] == k) cout << "yes" << "\n";
			else cout << "no" << "\n";
			continue;
		}
		
		bool flag = false;
		for(int i = 1; i <= n; i++){
			if(a[i] == k) flag = true;
		}
		if(!flag){
			cout << "no" << "\n";
			continue;
		}
		
		flag = false;
		for(int i = 1; i <= n-1; i++){
			if(a[i] >= k && a[i+1] >= k){
				flag = true;
				break;
			}
		}
		for(int i = 1; i <= n-2; i++){
			if(a[i] >= k && a[i+2] >= k){
				flag = true;
				break;
			}
		}
		if(flag) cout << "yes" << "\n";
		else cout << "no" << "\n";
	}
	flush(cout);
	
	return 0;
}