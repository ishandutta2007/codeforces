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

llint T, n;
llint a[2005];
vector<llint> ovec, evec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= 2*n; i++) cin >> a[i];
		
		ovec.clear(), evec.clear();
		for(int i = 1; i <= 2*n; i++){
			if(a[i]%2) ovec.push_back(i);
			else evec.push_back(i);
		}
		
		if(ovec.size()%2) ovec.pop_back();
		ovec.insert(ovec.end(), evec.begin(), evec.end());
		for(int i = 0; i < n-1; i++){
			cout << ovec[2*i] << " " << ovec[2*i+1] << endl;
		}
	}
	
	return 0;
}