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
int a[1005], b[1005];
bool used[1005];

int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			b[i] = a[i];
			used[i] = false;
		}
		
		vector<llint> ans;
		for(int i = 1; i <= n; i++){
			int mx = 0, mx_j;
			for(int j = 1; j <= n; j++){
				if(used[j]) continue;
				if(mx < a[j]){
					mx_j = j;
					mx = a[j];
				}
			}
			ans.push_back(b[mx_j]);
			used[mx_j] = true;
			for(int j = 1; j <= n; j++){
				if(!used[j]) a[j] = gcd(a[j], mx);
			}
		}
		for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";  cout << endl;
	}
	
	return 0;
}