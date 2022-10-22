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
vector<llint> vec, vec2, vec3;
llint p[1005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		if(n <= 3){
			cout << -1 << endl;
			continue;
		}
		
		vec.clear(), vec2.clear(), vec3.clear();
		for(int i = 1; i <= n; i++){
			if(i % 2) vec.push_back(i);
			else vec2.push_back(i);
		}
		swap(vec2[0], vec2[1]);
		reverse(vec2.begin(), vec2.end());
		
		for(int i = 0; i < vec2.size(); i++) vec3.push_back(vec2[i]);
		for(int i = 0; i < vec.size(); i++) vec3.push_back(vec[i]);
		
		for(int i = 1; i <= n; i++) cout << vec3[i-1] << " "; cout << endl;
	}
	
	return 0;
}