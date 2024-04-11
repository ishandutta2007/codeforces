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
llint n;
string s, t;
bool used[26];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int z = 0; z < T; z++){
		cin >> n >> s >> t;
		
		bool flag = true;
		for(int i = 0; i < n; i++){
			if(s[i] > t[i]){
				flag = false;
				break;
			}
		}
		if(!flag){
			cout << -1 << endl;
			continue;
		}
		
		llint ans = 0;
		for(int i = 0; i < 20; i++){
			char c = 'z';
			for(int j = 0; j < n; j++){
				if(s[j] == i+'a' && s[j] < t[j]) c = min(c, t[j]);
			}
			if(c == 'z') continue;
			ans++;
			for(int j = 0; j < n; j++){
				if(s[j] == i+'a' && s[j] < t[j]) s[j] = c;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}