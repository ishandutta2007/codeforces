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
llint a[5];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a[1] >> a[2] >> a[3];
	cout << "First" << endl;
	
	llint res, M = 10000000000;
	cout << M << endl;
	
	cin >> res;
	a[res] += M;
	
	vector<llint> vec;
	for(int i = 1; i <= 3; i++) vec.push_back(a[i]);
	sort(vec.rbegin(), vec.rend());
	M = 2*vec[0]-(vec[1]+vec[2]);
	cout << M << endl;
	
	cin >> res;
	a[res] += M;
	
	vec.clear();
	for(int i = 1; i <= 3; i++) vec.push_back(a[i]);
	sort(vec.rbegin(), vec.rend());
	M = vec[0]-vec[1];
	cout << M << endl;
	
	cin >> res;
	
	return 0;
}