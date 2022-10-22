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
llint a[55][55];
bool used[55][55];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				char c;
				cin >> c;
				a[i][j] = c%2;
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				used[i][j] = false;
			}
		}
		for(int i = n; i >= 1; i--){
			for(int j = n; j >= 1; j--){
				if(a[i][j] == 0) continue;
				if(i == n || j == n){
					used[i][j] = true;
					continue;
				}
				used[i][j] = used[i+1][j] || used[i][j+1];
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(a[i][j] == 1 && !used[i][j]){
					cout << "NO" << endl;
					goto end;
				}
			}
		}
		cout << "YES" << endl;
		end:;
	}
	
	return 0;
}