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
llint a[100005], b[100005];
vector<llint> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = n; i >= 1; i--){
		if(a[i-1] < a[i]){
			b[i] = a[i-1];
			for(int j = a[i-1]+1; j < a[i]; j++) vec.push_back(j);
		}
		else{
			if(vec.size()){
				b[i] = vec.back();
				vec.pop_back();
			}
			else b[i] = 1000000;
		}
	}
	if(vec.size()) cout << -1 << endl;
	else{
		for(int i = 1; i <= n; i++) cout << b[i] << " ";
		cout << endl;
	}

	return 0;
}