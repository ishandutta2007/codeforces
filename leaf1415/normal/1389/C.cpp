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
string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> s;
		
		llint ans = 0;
		for(int i = 0; i < 10; i++){
			llint cnt = 0;
			for(int j = 0; j < s.size(); j++){
				if(s[j]-'0' == i) cnt++;
			}
			ans = max(ans, cnt);
		}
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 10; j++){
				if(i == j) continue;
				bool flag = false; llint cnt = 0;
				for(int k = 0; k < s.size(); k++){
					if(flag && s[k]-'0' == j) cnt++, flag = false;
					else if(!flag && s[k]-'0' == i) cnt++, flag = true;
				}
				ans = max(ans, cnt/2*2);
			}
		}
		cout << (int)s.size() - ans << endl;
	}
	
	return 0;
}