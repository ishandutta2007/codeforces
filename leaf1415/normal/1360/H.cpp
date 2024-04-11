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
llint n, m;
vector<llint> vec;

llint dec(string &s)
{
	llint ret = 0;
	reverse(s.begin(), s.end());
	for(int i = 0; i < m; i++){
		if(s[i] == '1') ret += 1LL<<i;
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> m;
		
		vector<llint> vec; string s;
		for(int i = 1; i <= n; i++){
			cin >> s;
			vec.push_back(dec(s));
		}
		sort(vec.begin(), vec.end());
		
		llint M = 1LL<<(m-1), k = (1LL<<m)-n, ans;
		for(llint i = M-150; i <= M+150; i++){
			if(i < 0 || i >= (1LL<<m)) continue;
			llint p = lower_bound(vec.begin(), vec.end(), i) - vec.begin();
			if(vec[p] == i) continue;
			llint cnt = i - p;
			if(cnt == (k-1)/2){
				ans = i;
				break;
			}
		}
		
		s = "";
		for(int i = 0; i < m; i++){
			s += ans%2+'0';
			ans /= 2;
		}
		reverse(s.begin(), s.end());
		cout << s << endl;
	}
	
	return 0;
}