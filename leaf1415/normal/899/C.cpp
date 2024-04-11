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
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n;
vector<ll> ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	if(n % 4 == 2) ans.push_back(1);
	if(n % 4 == 3) ans.push_back(3);
	
	for(int i = n%4+1; i <= n; i+=4){
		ans.push_back(i);
		ans.push_back(i+3);
	}
	
	if(n % 4 == 0 || n % 4 == 3) cout << 0 << endl;
	else cout << 1 << endl;
	cout << ans.size() << " ";
	for(auto x : ans) cout << x << " "; cout << endl;
	
	return 0;
}