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
llint n, k;
llint a[105];
set<llint> S;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> k;
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		S.clear();
		for(int i = 1; i <= n; i++) S.insert(a[i]);
		if((int)S.size() > k){
			cout << -1 << endl;
			continue;
		}
		vector<llint> vec;
		for(auto it = S.begin(); it != S.end(); it++) vec.push_back(*it);
		while((int)vec.size() < k) vec.push_back(n);
		
		cout << n * k << endl;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < k; j++){
				cout << vec[j] << " ";
			}
		}
		cout << endl;
	}
	
	return 0;
}