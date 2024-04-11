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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)

using namespace std;

llint T;
llint n;
llint a[100005];
set<llint> S;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	rep(t, 0, T){
		cin >> n;
		Rep(i, 1, n) cin >> a[i];
		S.clear();
		Rep(i, 1, n) S.insert(a[i]);
		cout << S.size() << "\n";
	}
	flush(cout);
	
	return 0;
}