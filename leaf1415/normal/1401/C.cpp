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
vector<llint> vec, vec2;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		llint mn = inf;
		for(int i = 1; i <= n; i++) cin >> a[i], mn = min(mn, a[i]);
		
		vec.clear(), vec2.clear();
		for(int i = 1; i <= n; i++){
			if(a[i] % mn == 0){
				vec.push_back(a[i]);
				vec2.push_back(i);
			}
		}
		sort(vec.begin(), vec.end());
		sort(vec2.begin(), vec2.end());
		
		for(int i = 0; i < vec.size(); i++) a[vec2[i]] = vec[i];
		for(int i = 1; i < n; i++){
			if(a[i] > a[i+1]){
				cout << "NO" << endl;
				goto end;
			}
		}
		cout << "YES" << endl;
		end:;
	}
	
	return 0;
}