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
llint a[105], l[105];
vector<llint> vec, pvec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) cin >> l[i];
		
		vec.clear(), pvec.clear();
		for(int i = 1; i <= n; i++){
			if(l[i] == 0){
				vec.push_back(a[i]);
				pvec.push_back(i);
			}
		}
		sort(vec.rbegin(), vec.rend());
		
		for(int i = 0; i < pvec.size(); i++){
			a[pvec[i]] = vec[i];
		}
		for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
	}
	
	return 0;
}