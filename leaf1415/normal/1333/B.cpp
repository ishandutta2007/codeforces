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
llint a[100005], b[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) cin >> b[i];
		
		llint pos = -1;
		for(int i = 1; i <= n; i++){
			if(a[i] != 0){
				pos = i;
				break;
			}
		}
		if(pos == -1){
			bool flag = true;
			for(int i = 1; i <= n; i++){
				if(a[i] != b[i]){
					flag = false;
					break;
				}
			}
			if(flag) cout << "YES" << "\n";
			else cout << "NO" << "\n";
			continue;
		}
		
		if(a[pos] < 0){
			for(int i = 1; i <= n; i++) a[i] *= -1, b[i] *= -1;
		}
		
		llint neg = n;
		for(int i = pos+1; i <= n; i++){
			if(a[i] == -1){
				neg = i;
				break;
			}
		}
		
		bool flag = true;
		for(int i = pos+1; i <= neg; i++){
			if(a[i] > b[i]) flag = false;
		}
		for(int i = 1; i <= pos; i++){
			if(a[i] != b[i]) flag = false;
		}
		if(flag) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	flush(cout);
	
	return 0;
}