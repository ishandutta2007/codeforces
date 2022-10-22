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
string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> k;
		cin >> s;
		
		vector<llint> vec;
		llint cnt = 0, sum = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == 'L') cnt++, sum++;
			else{
				if(cnt > 0) vec.push_back(cnt);
				cnt = 0;
			}
		}
		if(cnt > 0) vec.push_back(cnt);
		
		if(sum == n){
			cout << max(0LL, 2*k-1) << endl;
			continue;
		}
		
		if(s[0] == 'L') vec.erase(vec.begin());
		if(s[n-1] == 'L') vec.pop_back();
		
		
		sort(vec.begin(), vec.end());
		llint a = 0, ans = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == 'W'){
				ans++;
				if(i > 0 && s[i-1] == 'W') ans++;
			}
		}
		
		for(int i = 0; i < vec.size(); i++){
			a += vec[i];
			if(a <= k) ans++;
		}
		
		ans += min(sum, k) * 2;
		cout << ans << endl;
	}
	
	return 0;
}