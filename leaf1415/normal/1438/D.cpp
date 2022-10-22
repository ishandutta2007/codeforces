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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

llint n;
llint a[100005];
vector<P> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	
	llint sum = 0;
	rep(i, 1, n) sum ^= a[i];
	if(n % 2 == 0 && sum){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	
	for(int i = 2; i+1 <= n; i+=2) vec.push_back(P(i, i+1));
	for(int i = 2; i+1 <= n; i+=2) vec.push_back(P(i, i+1));
	
	cout << vec.size() << endl;
	for(auto p: vec){
		cout << 1 << " " << p.first << " " << p.second << endl;
	}
	
	return 0;
}