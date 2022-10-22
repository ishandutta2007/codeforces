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
llint n0, n1, n2;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n0 >> n1 >> n2;
		
		string ans = "1";
		for(int i = 0; i < n1; i++) ans += i%2+'0';
		
		string s0, s2;
		for(int i = 0; i < n0; i++) s0 += "0";
		for(int i = 0; i < n2; i++) s2 += "1";
		
		if(n1 == 0 && n2 == 0){
			cout << 0;
			cout << s0 << endl;
			continue;
		}
		if(n1 == 0 && n0 == 0){
			cout << 1;
			cout << s2 << endl;
			continue;
		}
		
		for(int i = 0; i < ans.size(); i++){
			if(ans[i] == '0'){
				ans.insert(ans.begin()+i, s0.begin(), s0.end());
				break;
			}
		}
		for(int i = 0; i < ans.size(); i++){
			if(ans[i] == '1'){
				ans.insert(ans.begin()+i, s2.begin(), s2.end());
				break;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}