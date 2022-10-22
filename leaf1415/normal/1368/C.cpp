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

llint n;
vector<P> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	n++;
	for(int i = 0; i <= 2*n; i++) vec.push_back(P(i, 0));
	for(int i = 1; i <= n; i++){
		if(i%2){
			vec.push_back(P(i*2-2, -1));
			vec.push_back(P(i*2-2, -2));
			vec.push_back(P(i*2-1, -2));
			vec.push_back(P(i*2, -2));
			vec.push_back(P(i*2, -1));
		}
		else{
			vec.push_back(P(i*2-2, 1));
			vec.push_back(P(i*2-2, 2));
			vec.push_back(P(i*2-1, 2));
			vec.push_back(P(i*2, 2));
			vec.push_back(P(i*2, 1));
		}
	}
	
	cout << vec.size() << endl;
	for(int i = 0; i < vec.size(); i++) cout << vec[i].first << " " << vec[i].second << endl;
	
	return 0;
}