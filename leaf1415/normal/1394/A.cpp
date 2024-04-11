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

llint n, d, m;
vector<llint> vec, vec2;
vector<llint> svec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> d >> m;
	llint a;
	for(int i = 1; i <= n; i++){
		cin >> a;
		if(a > m) vec.push_back(a);
		else vec2.push_back(a);
	}
	for(int i = 1; i <= 2*d; i++) vec2.push_back(0);
	
	sort(vec.rbegin(), vec.rend());
	sort(vec2.rbegin(), vec2.rend());
	
	svec.push_back(0);
	for(int i = 0; i < vec2.size(); i++) svec.push_back(vec2[i] + svec.back());
	
	llint ans = -inf, sum = 0;
	for(int i = 0; i <= vec.size(); i++){
		llint rem = (n-i) - max(i-1, 0) * d;
		if(rem <= vec2.size() && rem >= 0){
			//cout << i << " " << rem << endl;
			ans = max(ans, svec[rem] + sum);
		}
		if(i < vec.size()) sum += vec[i];
	}
	cout << ans << endl;
	
	return 0;
}