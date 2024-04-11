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
vector<llint> vec, vec2;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		if(n/2%2){
			cout << "NO" << "\n";
			continue;
		}
		cout << "YES" << "\n";
		
		vec.clear(), vec2.clear();
		for(int i = 0; i < n/4; i++){
			vec.push_back(10*i+2);
			vec.push_back(10*i+4);
			vec2.push_back(10*i+1);
			vec2.push_back(10*i+5);
		}
		for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
		for(int i = 0; i < vec2.size(); i++) cout << vec2[i] << " ";
		cout << "\n";
	}
	flush(cout);
	return 0;
}